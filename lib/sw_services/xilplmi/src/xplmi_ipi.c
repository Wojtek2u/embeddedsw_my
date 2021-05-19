/******************************************************************************
* Copyright (c) 2018 - 2021 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/


/*****************************************************************************/
/**
 *
 * @file xplmi_ipi.c
 *
 * This is the file which contains ipi manager code.
 *
 * <pre>
 * MODIFICATION HISTORY:
 *
 * Ver   Who  Date        Changes
 * ----- ---- -------- -------------------------------------------------------
 * 1.00  ma   10/09/2018 Initial release
 * 1.01  kc   04/09/2019 Added code to register/enable/disable interrupts
 *       kc   05/21/2019 Updated IPI error code to response buffer
 *       ma   08/01/2019 Added LPD init code
 *       rv   02/04/2020 Set the 1st element of response array always to status
 *       bsv  02/13/2020 XilPlmi generic commands should not be supported
 *                       via IPI
 *       ma   02/21/2020 Added code to allow event logging command via IPI
 *       ma   02/28/2020 Added code to disallow EM commands over IPI
 *       bsv  03/09/2020 Added code to support CDO features command
 *       ma   03/19/2020 Added features command for EM module
 *       bsv  04/04/2020 Code clean up
 * 1.02  bsv  06/02/2020 Added code to support GET BOARD command and disallow
 *                       SET BOARD command via IPI
 *       bm   10/14/2020 Code clean up
 *       td   10/19/2020 MISRA C Fixes
 * 1.03  ma   02/12/2021 Return unique error codes in case of IPI read errors
 *       ma   03/04/2021 Code clean up
 *       ma   03/04/2021 Added access check for IPI commands
 *       ma   03/10/2021 Added code to disallow set image info Loader command
 *       bsv  03/24/2021 All IPIs to be acknowledged in XPlmi_IpiDispatchHandler
 *       bm   04/03/2021 Register IPI handler in IpiInit
 *       bsv  04/16/2021 Add provision to store Subsystem Id in XilPlmi
 *       bm   05/17/2021 Code cleanup
 *       bm   05/18/2021 Fix issue in IpiDispatchHandler
 *       har  05/18/2021 Updated Status to include library error code in case
 *                       of IPI access error
 *
 * </pre>
 *
 * @note
 *
 ******************************************************************************/
/***************************** Include Files *********************************/
#include "xplmi.h"
#include "xplmi_ipi.h"
#include "xplmi_proc.h"
#include "xplmi_generic.h"
#include "xplmi_hw.h"

#ifdef XPAR_XIPIPSU_0_DEVICE_ID
/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define XPLMI_IPI_XSDB_MASTER_MASK	IPI_PMC_ISR_IPI5_BIT_MASK
#define XPLMI_PMC_IMAGE_ID		(0x1C000001U)

/************************** Function Prototypes ******************************/
static int XPlmi_ValidateIpiCmd(XPlmi_Cmd *Cmd, u32 SrcIndex);
static u32 XPlmi_GetIpiReqType(u32 CmdId, u32 SrcIndex);
static XPlmi_SubsystemHandler XPlmi_GetPmSubsystemHandler(
	XPlmi_SubsystemHandler SubsystemHandler);

/************************** Variable Definitions *****************************/

/*****************************************************************************/
/* Instance of IPI Driver */
static XIpiPsu IpiInst;

/*****************************************************************************/
/**
 * @brief	This function stores address of XilPm API to retrieve
 * Subsystem Id based upon mask.
 *
 * @param	SubsystemHandler is handler to XilPm
 *		API called to retrieve Subsystem Id using Ipi mask
 *
 * @return	Address of XilPm API
 *
 *****************************************************************************/
static XPlmi_SubsystemHandler XPlmi_GetPmSubsystemHandler(
	XPlmi_SubsystemHandler SubsystemHandler)
{
	static XPlmi_SubsystemHandler Handler = NULL;

	if (SubsystemHandler != NULL) {
		Handler = SubsystemHandler;
	}

	return Handler;
}

/*****************************************************************************/
/**
 * @brief	This function initializes the IPI.
 *
 * @param	SubsystemHandler is handler to XilPm API called to retrieve
 *		Subsystem Id using Ipi mask
 *
 * @return	Status	IPI initialization status
 *
 *****************************************************************************/
int XPlmi_IpiInit(XPlmi_SubsystemHandler SubsystemHandler)
{
	int Status = XST_FAILURE;
	XIpiPsu_Config *IpiCfgPtr;
	u32 Index;

	/* Load Config for Processor IPI Channel */
	IpiCfgPtr = XIpiPsu_LookupConfig(XPAR_XIPIPSU_0_DEVICE_ID);
	if (IpiCfgPtr == NULL) {
		Status = XST_FAILURE;
		goto END;
	}

	/* Initialize the Instance pointer */
	Status = XIpiPsu_CfgInitialize(&IpiInst, IpiCfgPtr,
			IpiCfgPtr->BaseAddress);
	if (XST_SUCCESS != Status) {
		goto END;
	}

	/* Enable IPI from all Masters */
	for (Index = 0U; Index < XPLMI_IPI_MASK_COUNT; Index++) {
		XIpiPsu_InterruptEnable(&IpiInst,
			IpiCfgPtr->TargetList[Index].Mask);
	}

	Status = XPlmi_RegisterHandler(XPLMI_IPI_IRQ, XPlmi_IpiDispatchHandler,
			(void *)0U);
	if (Status != XST_SUCCESS) {
		goto END;
	}

	(void) XPlmi_GetPmSubsystemHandler(SubsystemHandler);
	/*
	 * Enable the IPI IRQ
	 */
	XPlmi_PlmIntrEnable(XPLMI_IPI_IRQ);

END:
	XPlmi_Printf(DEBUG_DETAILED,
			"%s: IPI init status: 0x%x\n\r", __func__, Status);
	return Status;
}

/*****************************************************************************/
/**
 * @brief	This is the handler for IPI interrupts.
 *
 * @param	Data is unused and required for compliance with other
 *          interrupt handlers.
 *
 * @return	XST_SUCCESS on success and error code on failure
 *
 *****************************************************************************/
int XPlmi_IpiDispatchHandler(void *Data)
{
	volatile int Status = XST_FAILURE;
	u32 SrcCpuMask;
	u32 Payload[XPLMI_IPI_MAX_MSG_LEN] = {0U};
	u32 MaskIndex;
	XPlmi_Cmd Cmd = {0U};
	int StatusTmp = XST_FAILURE;
	u8 PendingPsmIpi = (u8)FALSE;

	/* For MISRA C */
	(void )Data;

	SrcCpuMask = Xil_In32(IPI_PMC_ISR);

	for (MaskIndex = 0; MaskIndex < XPLMI_IPI_MASK_COUNT; MaskIndex++) {
		if ((SrcCpuMask & IpiInst.Config.TargetList[MaskIndex].Mask) != 0U) {
			Cmd.IpiReqType = XPLMI_CMD_NON_SECURE;
			Cmd.IpiMask = IpiInst.Config.TargetList[MaskIndex].Mask;
			if (IPI_PMC_ISR_PSM_BIT_MASK == Cmd.IpiMask) {
				PendingPsmIpi = (u8)TRUE;
			}
			Status = XPlmi_IpiRead(IpiInst.Config.TargetList[MaskIndex].Mask,
					&Payload[0U], XPLMI_IPI_MAX_MSG_LEN, XIPIPSU_BUF_TYPE_MSG);

			if (XST_SUCCESS != Status) {
				goto END;
			}

			Cmd.CmdId = Payload[0U];
			Status = XST_FAILURE;
			Status = XPlmi_ValidateIpiCmd(&Cmd,
					IpiInst.Config.TargetList[MaskIndex].BufferIndex);
			if (Status != XST_SUCCESS) {
				goto END;
			}

			Cmd.Len = (Cmd.CmdId >> 16U) & 255U;
			if (Cmd.Len > XPLMI_MAX_IPI_CMD_LEN) {
				Cmd.Len = Payload[1U];
				Cmd.Payload = (u32 *)&Payload[2U];
			} else {
				Cmd.Payload = (u32 *)&Payload[1U];
			}

			/* Ack PSM IPIs before running handlers */
			if (IPI_PMC_ISR_PSM_BIT_MASK == Cmd.IpiMask) {
				PendingPsmIpi = (u8)FALSE;
				XPlmi_Out32(IPI_PMC_ISR,
					IPI_PMC_ISR_PSM_BIT_MASK);
			}

			Status = XPlmi_CmdExecute(&Cmd);

END:
			Cmd.Response[0U] = (u32)Status;
			/* Send response to caller */
			(void)XPlmi_IpiWrite(Cmd.IpiMask, Cmd.Response,
					XPLMI_CMD_RESP_SIZE, XIPIPSU_BUF_TYPE_RESP);
			/* Ack all IPIs */
			if ((LpdInitialized & LPD_INITIALIZED) == LPD_INITIALIZED) {
				if ((IPI_PMC_ISR_PSM_BIT_MASK != Cmd.IpiMask) ||
					(PendingPsmIpi == (u8)TRUE)) {
						XPlmi_Out32(IPI_PMC_ISR, Cmd.IpiMask);
				}
			}
		}
	}

	if (XST_SUCCESS != Status) {
		XPlmi_Printf(DEBUG_GENERAL, "%s: Error: Unhandled IPI received\n\r", __func__);
	} else {
		XPlmi_Printf(DEBUG_DETAILED, "%s: IPI processed.\n\r", __func__);
	}

	/* Clear and enable the GIC IPI interrupt */
	StatusTmp = XPlmi_PlmIntrClear(XPLMI_IPI_IRQ);
	if ((StatusTmp != XST_SUCCESS) && (Status == XST_SUCCESS)) {
		Status = StatusTmp;
	}
	XPlmi_PlmIntrEnable(XPLMI_IPI_IRQ);

	return Status;
}

/*****************************************************************************/
/**
 * @brief	This function writes an IPI message or a response to
 * destination CPU.
 *
 * @param	DestCpuMask Destination CPU IPI mask
 * 		MsgPtr		Pointer to message to be written
 * 		MsgLen		IPI message length
 * 		Type		IPI buffer type
 *
 * @return	XST_SUCCESS on success and error code on failure
 *
 *****************************************************************************/
int XPlmi_IpiWrite(u32 DestCpuMask, u32 *MsgPtr, u32 MsgLen, u8 Type)
{
	int Status = XST_FAILURE;

	if ((LpdInitialized & LPD_INITIALIZED) == LPD_INITIALIZED) {
		if ((NULL != MsgPtr) &&
			((MsgLen != 0U) && (MsgLen <= XPLMI_IPI_MAX_MSG_LEN)) &&
			((XIPIPSU_BUF_TYPE_MSG == Type) || (XIPIPSU_BUF_TYPE_RESP == Type))) {
			Status = XIpiPsu_WriteMessage(&IpiInst, DestCpuMask,
				MsgPtr, MsgLen, Type);
			if (Status != XST_SUCCESS) {
				goto END;
			}
		}
	}

END:
	XPlmi_Printf(DEBUG_DETAILED, "%s: IPI write status: 0x%x\r\n",
				__func__, Status);
	return Status;
}

/*****************************************************************************/
/**
 * @brief	This function reads an IPI message or response from source CPU.
 *
 * @param	SrcCpuMask	Source CPU IPI mask
 * 		MsgPtr 		IPI read message buffer
 * 		MsgLen		IPI message length
 * 		Type		IPI buffer type
 *
 * @return	XST_SUCCESS on success and error code on failure
 *
 *****************************************************************************/
int XPlmi_IpiRead(u32 SrcCpuMask, u32 *MsgPtr, u32 MsgLen, u8 Type)
{
	int Status = XST_FAILURE;

	if ((NULL != MsgPtr) && ((MsgLen != 0U) && (MsgLen <= XPLMI_IPI_MAX_MSG_LEN)) &&
		((XIPIPSU_BUF_TYPE_MSG == Type) || (XIPIPSU_BUF_TYPE_RESP == Type))) {
		/* Read Entire Message to Buffer */
		Status = XIpiPsu_ReadMessage(&IpiInst, SrcCpuMask, MsgPtr, MsgLen,
				Type);
		if (Status != XST_SUCCESS) {
			if (XIPIPSU_CRC_ERROR == Status) {
				XPlmi_Printf(DEBUG_GENERAL,
						"%s: IPI CRC validation failed\r\n", __func__);
				Status = XPlmi_UpdateStatus(XPLMI_IPI_CRC_MISMATCH_ERR, 0);
			} else {
				XPlmi_Printf(DEBUG_GENERAL,
						"%s: IPI Buffer address or Message Length "
						"is invalid\r\n", __func__);
				Status = XPlmi_UpdateStatus(XPLMI_IPI_READ_ERR, 0);
			}
			goto END;
		}
	}

END:
	XPlmi_Printf(DEBUG_DETAILED, "%s: IPI read status: 0x%x\r\n", __func__, Status);
	return Status;
}

/*****************************************************************************/
/**
 * @brief	This function triggers the IPI interrupt to destination CPU.
 *
 * @param	DestCpuMask Destination CPU IPI mask
 *
 * @return	XST_SUCCESS on success and error code on failure
 *
 *****************************************************************************/
int XPlmi_IpiTrigger(u32 DestCpuMask)
{
	int Status = XST_FAILURE;

	Status = XIpiPsu_TriggerIpi(&IpiInst, DestCpuMask);

	return Status;
}

/*****************************************************************************/
/**
 * @brief	This function polls for IPI acknowledgment from destination CPU.
 *
 * @param	DestCpuMask Destination CPU IPI mask
 * 		TimeOutCount Timeout value
 *
 * @return	XST_SUCCESS on success and error code on failure
 *
 *****************************************************************************/
int XPlmi_IpiPollForAck(u32 DestCpuMask, u32 TimeOutCount)
{
	int Status = XST_FAILURE;

	Status = XIpiPsu_PollForAck(&IpiInst, DestCpuMask, TimeOutCount);

	return Status;
}

/*****************************************************************************/
/**
 * @brief	This function checks whether the Cmd passed is supported
 * 			via IPI mechanism or not.
 *
 * @param	ModuleId is the module ID
 * @param	ApiId is the API ID
 *
 * @return	XST_SUCCESS on success and XST_FAILURE on failure
 *
 *****************************************************************************/
static int XPlmi_ValidateCmd(u32 ModuleId, u32 ApiId)
{
	int Status = XST_FAILURE;

	/* Validate IPI Command */
	switch (ModuleId) {
		case XPLMI_MODULE_GENERIC_ID:
			/*
			 * Only Device ID, Event Logging and Get Board
			 * commands are allowed through IPI.
			 * All other commands are allowed only from CDO file.
			 */
			if ((ApiId == XPLMI_PLM_GENERIC_DEVICE_ID_VAL) ||
					(ApiId == XPLMI_PLM_GENERIC_EVENT_LOGGING_VAL) ||
					(ApiId == XPLMI_PLM_MODULES_FEATURES_VAL) ||
					(ApiId == XPLMI_PLM_MODULES_GET_BOARD_VAL)) {
				Status = XST_SUCCESS;
			}
			break;

		case XPLMI_MODULE_ERROR_ID:
			/*
			 * Only features command is allowed in EM module through IPI.
			 * Other EM commands are allowed only from CDO file.
			 */
			if (ApiId == XPLMI_PLM_MODULES_FEATURES_VAL) {
				Status = XST_SUCCESS;
			}
			break;

		case XPLMI_MODULE_LOADER_ID:
			/*
			 * Except Set Image Info command, all other commands are allowed
			 * in Loader module through IPI.
			 */
			if (ApiId != XPLMI_PLM_LOADER_SET_IMG_INFO_VAL) {
				Status = XST_SUCCESS;
			}
			break;

		default:
			/* Other module's commands are allowed through IPI */
			Status = XST_SUCCESS;
			break;
	}

	return Status;
}

/*****************************************************************************/
/**
 * @brief	This function checks whether the Cmd passed is supported
 * 			via IPI mechanism or not.
 *
 * @param	Cmd is the pointer to Cmd structure
 * @param	SrcIndex is the source index of IPI command
 *
 * @return	XST_SUCCESS on success and error code on failure
 *
 *****************************************************************************/
static int XPlmi_ValidateIpiCmd(XPlmi_Cmd *Cmd, u32 SrcIndex)
{
	volatile int Status = XST_FAILURE;
	u32 CmdHndlr = (Cmd->CmdId & XPLMI_CMD_MODULE_ID_MASK) >>
			XPLMI_CMD_MODULE_ID_SHIFT;
	u32 ApiId = Cmd->CmdId & XPLMI_PLM_GENERIC_CMD_ID_MASK;

	/* Validate module number and source IPI index*/
	if ((CmdHndlr >= XPLMI_MAX_MODULES) ||
		(SrcIndex == IPI_NO_BUF_CHANNEL_INDEX)) {
		/* Return error code if IPI validation failed */
		Status = XPlmi_UpdateStatus(XPLMI_ERR_IPI_CMD, 0);
		goto END;
	}

	/* Validate IPI Command */
	Status = XPlmi_ValidateCmd(CmdHndlr, ApiId);
	if (XST_SUCCESS != Status) {
		/* Return error code if IPI validation failed */
		Status = XPlmi_UpdateStatus(XPLMI_ERR_IPI_CMD, 0);
		goto END;
	}

	/* Get Subsystem Id */
	if (Cmd->IpiMask == XPLMI_IPI_XSDB_MASTER_MASK) {
		Cmd->SubsystemId = XPLMI_PMC_IMAGE_ID;
	}
	else {
		Cmd->SubsystemId =
			(*XPlmi_GetPmSubsystemHandler(NULL))(Cmd->IpiMask);
	}

	/* Get IPI request type */
	Cmd->IpiReqType = XPlmi_GetIpiReqType(Cmd->CmdId, SrcIndex);
	/*
	 * Check command IPI access if module has registered the handler
	 * If handler is not registered, do nothing
	 */
	if (Modules[CmdHndlr]->CheckIpiAccess != NULL) {
		Status = XST_FAILURE;
		Status = Modules[CmdHndlr]->CheckIpiAccess(Cmd->CmdId,
				Cmd->IpiReqType);
		/* Return error code if IPI access failed */
		if (XST_SUCCESS != Status) {
			Status = XPlmi_UpdateStatus(XPLMI_IPI_ACCESS_ERR,
				Status);
		}
	}

END:
	return Status;
}

/*****************************************************************************/
/**
 * @brief	This function checks for the IPI command access permission and
 *          returns IPI request type to the caller
 *
 * @param	CmdId is command ID
 * @param	SrcIndex is the source IPI index
 *
 * @return	IpiReqType IPI command request type
 *
 *****************************************************************************/
static u32 XPlmi_GetIpiReqType(u32 CmdId, u32 SrcIndex)
{
	u32 CmdPerm = CmdId & IPI_CMD_HDR_SECURE_BIT_MASK;
	volatile u32 ChannelPerm = XPLMI_CMD_NON_SECURE;
	volatile u32 ChannelPermTmp = XPLMI_CMD_NON_SECURE;
	u32 IpiReqType = XPLMI_CMD_NON_SECURE;

	/* Treat command as non-secure if Command type is non-secure */
	if (XPLMI_CMD_SECURE != CmdPerm) {
		goto END;
	}

	/*
	 * Read source agent IPI aperture TZ register
	 * and check source to PMC request type
	 */
	ChannelPerm = XPlmi_In32((IPI_APER_TZ_000_ADDR +
			(SrcIndex * XPLMI_WORD_LEN)));
	ChannelPermTmp = XPlmi_In32((IPI_APER_TZ_000_ADDR +
			(SrcIndex * XPLMI_WORD_LEN)));
	ChannelPerm &= IPI_APER_TZ_PMC_REQ_BUF_MASK;
	ChannelPermTmp &= IPI_APER_TZ_PMC_REQ_BUF_MASK;

	/*
	 * Request type is secure if both Channel type and Command type
	 * are secure
	 */
	if ((ChannelPerm == XPLMI_CMD_SECURE) &&
		(ChannelPermTmp == XPLMI_CMD_SECURE)) {
		IpiReqType = XPLMI_CMD_SECURE;
	}

END:
	return IpiReqType;
}
#endif /* XPAR_XIPIPSU_0_DEVICE_ID */
