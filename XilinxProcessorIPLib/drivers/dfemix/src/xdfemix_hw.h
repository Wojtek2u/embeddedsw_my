/******************************************************************************
* Copyright (C) 2021 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

/*****************************************************************************/
/**
*
* @file xdfemix_reg.h
* @addtogroup xdfemix_v1_2
* @{
* @cond nocomments
* Contains the register definitions for dfemixer. This is
* created to be used initially while waiting for IP.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who    Date     Changes
* ----- ---    -------- -----------------------------------------------
* 1.0   dc     07/22/20 Initial version
*       dc     02/15/21 align driver to curent specification
*       dc     03/18/21 New model parameter list
*       dc     04/14/21 Add FIR_ENABLE/MIXER_ENABLE register support
*       dc     04/20/21 Doxygen documentation update
*       dc     05/08/21 Update to common trigger
*       dc     05/18/21 Handling CCUpdate trigger
* 1.1   dc     07/13/21 Update to common latency requirements
* 1.2   dc     10/29/21 Update doxygen comments
*       dc     11/01/21 Add multi AddCC, RemoveCC and UpdateCC
*
* </pre>
*
******************************************************************************/
#ifndef XDFEMIX_HW_H_
#define XDFEMIX_HW_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************** Definitions *******************************/
/* CORE functionality */
#define XDFEMIX_VERSION_OFFSET 0x00U /* Register offset */
#define XDFEMIX_VERSION_PATCH_WIDTH 8U
#define XDFEMIX_VERSION_PATCH_OFFSET 0U
#define XDFEMIX_VERSION_REVISION_WIDTH 8U
#define XDFEMIX_VERSION_REVISION_OFFSET 8U
#define XDFEMIX_VERSION_MINOR_WIDTH 8U
#define XDFEMIX_VERSION_MINOR_OFFSET 16U
#define XDFEMIX_VERSION_MAJOR_WIDTH 8U
#define XDFEMIX_VERSION_MAJOR_OFFSET 24U

#define XDFEMIX_RESET_OFFSET 0x04U /* Register offset */
#define XDFEMIX_RESET_OFF 0x00U
#define XDFEMIX_RESET_ON 0x01U

#define XDFEMIX_MODEL_PARAM_1_OFFSET 0x08U /* Register offset */
#define XDFEMIX_MODEL_PARAM_1_MODE_WIDTH 1U
#define XDFEMIX_MODEL_PARAM_1_MODE_OFFSET 0U
#define XDFEMIX_MODEL_PARAM_1_DOWNLINK 0U
#define XDFEMIX_MODEL_PARAM_1_UPLINK 1U
#define XDFEMIX_MODEL_PARAM_1_NUM_ANTENNA_WIDTH 4U
#define XDFEMIX_MODEL_PARAM_1_NUM_ANTENNA_OFFSET 4U
#define XDFEMIX_MODEL_PARAM_1_MAX_USEABLE_CCIDS_WIDTH 4U
#define XDFEMIX_MODEL_PARAM_1_MAX_USEABLE_CCIDS_OFFSET 8U
#define XDFEMIX_MODEL_PARAM_1_LANES_WIDTH 3U
#define XDFEMIX_MODEL_PARAM_1_LANES_OFFSET 12U
#define XDFEMIX_MODEL_PARAM_1_ANTENNA_INTERLEAVE_WIDTH 4U
#define XDFEMIX_MODEL_PARAM_1_ANTENNA_INTERLEAVE_OFFSET 16U
#define XDFEMIX_MODEL_PARAM_1_MIXER_CPS_WIDTH 3U
#define XDFEMIX_MODEL_PARAM_1_MIXER_CPS_OFFSET 20U

#define XDFEMIX_MODEL_PARAM_2_OFFSET 0x0CU /* Register offset */
#define XDFEMIX_MODEL_PARAM_2_DATA_IWIDTH_WIDTH 5U
#define XDFEMIX_MODEL_PARAM_2_DATA_IWIDTH_OFFSET 0U
#define XDFEMIX_MODEL_PARAM_2_DATA_OWIDTH_WIDTH 5U
#define XDFEMIX_MODEL_PARAM_2_DATA_OWIDTH_OFFSET 8U
#define XDFEMIX_MODEL_PARAM_2_TUSER_WIDTH_WIDTH 7U
#define XDFEMIX_MODEL_PARAM_2_TUSER_WIDTH_OFFSET 16U

/* State */
#define XDFEMIX_STATE_OPERATIONAL_OFFSET 0x10U /* Register offset */
#define XDFEMIX_STATE_OPERATIONAL_FIELD_WIDTH 0x1U
#define XDFEMIX_STATE_OPERATIONAL_FIELD_OFFSET 0x0U
#define XDFEMIX_STATE_OPERATIONAL_NO 0x0U
#define XDFEMIX_STATE_OPERATIONAL_YES 0x1U
#define XDFEMIX_STATE_LOW_POWER_OFFSET 0x14U /* Register offset */
#define XDFEMIX_STATE_ACTIVE 0x0U
#define XDFEMIX_STATE_LOW_POWER 0x1U
#define XDFEMIX_STATE_FIR_ENABLE_OFFSET 0x18U /* Register offset */
#define XDFEMIX_STATE_FIR_DISABLED 0x0U
#define XDFEMIX_STATE_FIR_ENABLED 0x1U
#define XDFEMIX_STATE_MIXER_ENABLE_OFFSET 0x1CU /* Register offset */
#define XDFEMIX_STATE_MIXER_DISABLED 0x0U
#define XDFEMIX_STATE_MIXER_ENABLED 0x1U

/* Triggers */
#define XDFEMIX_TRIGGERS_ACTIVATE_OFFSET 0x20U /* Register offset */
#define XDFEMIX_TRIGGERS_LOW_POWER_OFFSET 0x28U /* Register offset */
#define XDFEMIX_TRIGGERS_CC_UPDATE_OFFSET 0x2CU /* Register offset */
/* Bit fields */
#define XDFEMIX_TRIGGERS_TRIGGER_ENABLE_WIDTH 1U
#define XDFEMIX_TRIGGERS_TRIGGER_ENABLE_OFFSET 0U
#define XDFEMIX_TRIGGERS_TRIGGER_ENABLE_DISABLED 0U
#define XDFEMIX_TRIGGERS_TRIGGER_ENABLE_ENABLED 1U
#define XDFEMIX_TRIGGERS_MODE_WIDTH 2U
#define XDFEMIX_TRIGGERS_MODE_OFFSET 4U
#define XDFEMIX_TRIGGERS_MODE_IMMEDIATE 0U
#define XDFEMIX_TRIGGERS_MODE_TUSER_SINGLE_SHOT 1U
#define XDFEMIX_TRIGGERS_MODE_TUSER_CONTINUOUS 2U
#define XDFEMIX_TRIGGERS_MODE_RESERVED 3U
#define XDFEMIX_TRIGGERS_TUSER_EDGE_LEVEL_WIDTH 2U
#define XDFEMIX_TRIGGERS_TUSER_EDGE_LEVEL_OFFSET 8U
#define XDFEMIX_TRIGGERS_TUSER_EDGE_LEVEL_LOW 0U
#define XDFEMIX_TRIGGERS_TUSER_EDGE_LEVEL_HIGH 1U
#define XDFEMIX_TRIGGERS_TUSER_EDGE_LEVEL_FALING 2U
#define XDFEMIX_TRIGGERS_TUSER_EDGE_LEVEL_RISING 3U
#define XDFEMIX_TRIGGERS_STATE_OUTPUT_WIDTH 1U
#define XDFEMIX_TRIGGERS_STATE_OUTPUT_OFFSET 12U
#define XDFEMIX_TRIGGERS_STATE_OUTPUT_DISABLED 0U
#define XDFEMIX_TRIGGERS_STATE_OUTPUT_ENABLED 1U
#define XDFEMIX_TRIGGERS_TUSER_BIT_WIDTH 8U
#define XDFEMIX_TRIGGERS_TUSER_BIT_OFFSET 16U

/* IRQ status */
#define XDFEMIX_ISR 0x34U /* Register offset */
#define XDFEMIX_ISR_HAS_NOT_OCCURRED 0U
#define XDFEMIX_ISR_OCCURRED 1U
#define XDFEMIX_IER 0x38U /* Register offset */
#define XDFEMIX_IER_NO_CHANGE 0U
#define XDFEMIX_IER_SET_BIT 1U
#define XDFEMIX_IDR 0x3CU /* Register offset */
#define XDFEMIX_IDR_NO_CHANGE 0U
#define XDFEMIX_IDR_SET_BIT 1U
#define XDFEMIX_IMR 0x40U /* Register offset */
#define XDFEMIX_IMR_INTERRUPT 0U
#define XDFEMIX_IMR_NO_INTERRUPT 1U

#define XDFEMIX_DUC_DDC_OVERFLOW_WIDTH 1U
#define XDFEMIX_DUC_DDC_OVERFLOW_OFFSET 0U
#define XDFEMIX_MIXER_OVERFLOW_WIDTH 1U
#define XDFEMIX_MIXER_OVERFLOW_OFFSET 1U
#define XDFEMIX_CC_UPDATE_TRIGGERED_WIDTH 1U
#define XDFEMIX_CC_UPDATE_TRIGGERED_OFFSET 2U
#define XDFEMIX_CC_UPDATE_TRIGGERED_LOW 0U
#define XDFEMIX_CC_UPDATE_TRIGGERED_HIGH 1U
#define XDFEMIX_CC_SEQUENCE_ERROR_WIDTH 1U
#define XDFEMIX_CC_SEQUENCE_ERROR_OFFSET 3U
#define XDFEMIX_IRQ_FLAGS_MASK 0xFU

/* Delay */
#define XDFEMIX_PL_MIXER_DELAY 0x44U /* Register offset */
#define XDFEMIX_PL_MIXER_DELAY_WIDTH 3U
#define XDFEMIX_PL_MIXER_DELAY_OFFSET 0U
#define XDFEMIX_PL_MIXER_DELAY_VALUE 2U
#define XDFEMIX_DELAY_OFFSET 0x80U /**< Register offset */
#define XDFEMIX_DELAY_VALUE_WIDTH 10U
#define XDFEMIX_DELAY_VALUE_OFFSET 0U
#define XDFEMIX_LATENCY_OFFSET 0x84U /**< Register offset */
#define XDFEMIX_LATENCY_VALUE_WIDTH 7U
#define XDFEMIX_LATENCY_VALUE_OFFSET 0U

/* CC_Configuration */
#define XDFEMIX_ANTENNA_GAIN_CURRENT 0x1000U /* Register offset */
#define XDFEMIX_ANTENNA_GAIN_NEXT 0x1004U /* Register offset */
#define XDFEMIX_ANTENNA_GAIN_WIDTH 8U
#define XDFEMIX_ANTENNA_GAIN_OFFSET 0U
#define XDFEMIX_ONE_ANTENNA_GAIN_WIDTH 1U
#define XDFEMIX_ONE_ANTENNA_GAIN_MINUS6DB 0U
#define XDFEMIX_ONE_ANTENNA_GAIN_ZERODB 1U

#define XDFEMIX_SEQUENCE_LENGTH_CURRENT 0x1010U /* Register offset */
#define XDFEMIX_SEQUENCE_LENGTH_NEXT 0x1014U /* Register offset */
#define XDFEMIX_SEQUENCE_LENGTH_WIDTH 4U
#define XDFEMIX_SEQUENCE_LENGTH_OFFSET 0U

#define XDFEMIX_SEQUENCE_CURRENT 0x1100U /* Register offset */
#define XDFEMIX_SEQUENCE_NEXT 0x1140U /* Register offset */
#define XDFEMIX_SEQUENCE_WIDTH 4U
#define XDFEMIX_SEQUENCE_OFFSET 0U
#define XDFEMIX_SEQUENCE_SIZE 16U

/* Carrier configuration */
#define XDFEMIX_CC_CONFIG_CURRENT 0x1200U /* Register offset */
#define XDFEMIX_CC_CONFIG_NEXT 0x1240U /* Register offset */
#define XDFEMIX_CC_CONFIG_SIZE 16U
#define XDFEMIX_CC_CONFIG_NCO_WIDTH 3U
#define XDFEMIX_CC_CONFIG_NCO_OFFSET 0U
#define XDFEMIX_CC_CONFIG_RATE_WIDTH 3U
#define XDFEMIX_CC_CONFIG_RATE_OFFSET 4U
#define XDFEMIX_CC_CONFIG_RATE_DISABLED 0U
#define XDFEMIX_CC_CONFIG_RATE_1X 1U
#define XDFEMIX_CC_CONFIG_RATE_2X 2U
#define XDFEMIX_CC_CONFIG_RATE_4X 3U
#define XDFEMIX_CC_CONFIG_RATE_8X 4U
#define XDFEMIX_CC_CONFIG_RATE_16X 5U
#define XDFEMIX_CC_CONFIG_CC_GAIN_WIDTH 2U
#define XDFEMIX_CC_CONFIG_CC_GAIN_OFFSET 8U
#define XDFEMIX_CC_CONFIG_CC_GAIN_MINUS18DB 0U
#define XDFEMIX_CC_CONFIG_CC_GAIN_MINUS12DB 1U
#define XDFEMIX_CC_CONFIG_CC_GAIN_MINUS6DB 2U
#define XDFEMIX_CC_CONFIG_CC_GAIN_ZERODB 3U

/* DUC_DDC status */
#define XDFEMIX_DUC_DDC_STATUS_OVERFLOW 0x2000U /* Register offset */
#define XDFEMIX_DUC_DDC_STATUS_OVERFLOW_STAGE_WIDTH 2U
#define XDFEMIX_DUC_DDC_STATUS_OVERFLOW_STAGE_OFFSET 0U
#define XDFEMIX_DUC_DDC_STATUS_OVERFLOW_ANTENNA_WIDTH 3U
#define XDFEMIX_DUC_DDC_STATUS_OVERFLOW_ANTENNA_OFFSET 4U
#define XDFEMIX_DUC_DDC_STATUS_OVERFLOW_ASSOCIATED_NCO_WIDTH 4U
#define XDFEMIX_DUC_DDC_STATUS_OVERFLOW_ASSOCIATED_NCO_OFFSET 8U

/* Mixer configuration */
#define XDFEMIX_MIXER_PHASE_CAPTURE 0x3000U /* Register offset */
#define XDFEMIX_MIXER_PHASE_CAPTURE_OFF 0U
#define XDFEMIX_MIXER_PHASE_CAPTURE_ON 1U
/* Mixer Status */
#define XDFEMIX_MIXER_STATUS_OVERFLOW 0x3004U /* Register offset */
#define XDFEMIX_MIXER_STATUS_OVERFLOW_STAGE_WIDTH 2U
#define XDFEMIX_MIXER_STATUS_OVERFLOW_STAGE_OFFSET 0U
#define XDFEMIX_MIXER_STATUS_OVERFLOW_STAGE_COMPLEX_MULT 0U
#define XDFEMIX_MIXER_STATUS_OVERFLOW_STAGE_FIRST_ADDER 1U
#define XDFEMIX_MIXER_STATUS_OVERFLOW_STAGE_SECOND_ADDER 2U
#define XDFEMIX_MIXER_STATUS_OVERFLOW_ANTENNA_WIDTH 3U
#define XDFEMIX_MIXER_STATUS_OVERFLOW_ANTENNA_OFFSET 4U
#define XDFEMIX_MIXER_STATUS_OVERFLOW_NCO_WIDTH 4U
#define XDFEMIX_MIXER_STATUS_OVERFLOW_NCO_OFFSET 8U

/* PHACC configuration */
#define XDFEMIX_FREQ_CONTROL_WORD 0x4400U /* Register offset */
#define XDFEMIX_FREQ_SINGLE_MOD_COUNT 0x4404U /* Register offset */
#define XDFEMIX_FREQ_DUAL_MOD_COUNT 0x4408U /* Register offset */
#define XDFEMIX_FREQ_PHASE_OFFSET 0x440CU /* Register offset */
#define XDFEMIX_PHASE_UPDATE_ACC 0x4410U /* Register offset */
#define XDFEMIX_PHASE_UPDATE_DUAL_MOD_COUNT 0x4414U /* Register offset */
#define XDFEMIX_PHASE_UPDATE_DUAL_MOD_SEL 0x4418U /* Register offset */
#define XDFEMIX_NCO_GAIN 0x441CU /* Register offset */
#define XDFEMIX_PHASE_CAPTURE_ACC 0x4420U /* Register offset */
#define XDFEMIX_PHASE_CAPTURE_DUAL_MOD_COUNT 0x4424U /* Register offset */
#define XDFEMIX_PHASE_CAPTURE_DUAL_MOD_SEL 0x4428U /* Register offset */
#define XDFEMIX_FREQ_UPDATE 0x442CU /* Register offset */
#define XDFEMIX_PHASE_UPDATE 0x4430U /* Register offset */
#define XDFEMIX_PHASE_RESET 0x4434U /* Register offset */
#define XDFEMIX_PHASE_ACC_ENABLE 0x4438U /* Register offset */

#define XDFEMIX_PHAC_CCID_ADDR_STEP 0x40U
#define XDFEMIX_NCO_GAIN_ZERODB 0U /* Apply 0dB gain */
#define XDFEMIX_NCO_GAIN_MINUS3DB 1U /* Apply 3dB gain */
#define XDFEMIX_NCO_GAIN_MINUS6DB 2U /* Apply 6dB gain */
#define XDFEMIX_NCO_GAIN_MINUS9DB 3U /* Apply 9dB gain */

#ifdef __cplusplus
}
#endif

#endif
/**
* @endcond
*/
/** @} */
