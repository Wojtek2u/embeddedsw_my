/******************************************************************************
* Copyright (c) 2022 Xilinx, Inc.  All rights reserved.
* Copyright (c) 2022 - 2023 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

/*****************************************************************************/
/**
*
* @file psmx_global.h
*
* This file contains PSM Global definitions used by PSM Firmware
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver	Who		Date		Changes
* ---- ---- -------- ------------------------------
* 1.00  sr   03/03/2022 Initial release
*
* </pre>
*
* @note
*
******************************************************************************/

#ifndef XPSMFW_PSMX_GLOBAL_H_
#define XPSMFW_PSMX_GLOBAL_H_


#ifdef __cplusplus
extern "C" {
#endif

/**
 * PSMX_GLOBAL_REG Base Address
 */
#define PSMX_GLOBAL_REG_BASEADDR      ((u32)0xEBC90000U)

/**
 * Register: PSMX_GLOBAL_REG_GLOBAL_CNTRL
 */
#define PSMX_GLOBAL_REG_GLOBAL_CNTRL    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000000U )

#define PSMX_GLOBAL_REG_GLOBAL_CNTRL_FW_IS_PRESENT_MASK    (u32)0x00000010U
#define PSMX_GLOBAL_REG_GLOBAL_CNTRL_FW_IS_PRESENT_DEFVAL  (u32)0x0U

/**
 * Register: PSMX_GLOBAL_REG_PWR_STATE0
 */
#define PSMX_GLOBAL_REG_PWR_STATE0    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000100U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRUP0_INT_MASK
 */
#define PSMX_GLOBAL_REG_REQ_PWRUP0_INT_MASK    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000114U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS
 */
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000110U )
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_FP_MASK    (u32)0x00100000U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU3_CORE3_MASK    (u32)0x00008000U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU3_CORE2_MASK    (u32)0x00004000U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU3_CORE1_MASK    (u32)0x00002000U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU3_CORE0_MASK    (u32)0x00001000U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU2_CORE3_MASK    (u32)0x00000800U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU2_CORE2_MASK    (u32)0x00000400U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU2_CORE1_MASK    (u32)0x00000200U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU2_CORE0_MASK    (u32)0x00000100U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU1_CORE3_MASK    (u32)0x00000080U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU1_CORE2_MASK    (u32)0x00000040U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU1_CORE1_MASK    (u32)0x00000020U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU1_CORE0_MASK    (u32)0x00000010U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU0_CORE3_MASK    (u32)0x00000008U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU0_CORE2_MASK    (u32)0x00000004U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU0_CORE1_MASK    (u32)0x00000002U
#define PSMX_GLOBAL_REG_REQ_PWRUP0_STATUS_APU0_CORE0_MASK    (u32)0x00000001U

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRUP0_INT_EN
 */
#define PSMX_GLOBAL_REG_REQ_PWRUP0_INT_EN    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000118U )


/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRUP0_INT_DIS
 */
#define PSMX_GLOBAL_REG_REQ_PWRUP0_INT_DIS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x0000011CU )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRUP0_TRIG
 */
#define PSMX_GLOBAL_REG_REQ_PWRUP0_TRIG    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000120U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS
 */
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000124U )

#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_GEM1_MASK    (u32)0x20000000U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_GEM0_MASK    (u32)0x10000000U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_TCM1B_MASK    (u32)0x00800000U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_TCM1A_MASK    (u32)0x00400000U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_TCM0B_MASK    (u32)0x00200000U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_TCM0A_MASK    (u32)0x00100000U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_OCM_ISLAND7_MASK    (u32)0x00000800U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_OCM_ISLAND6_MASK    (u32)0x00000400U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_OCM_ISLAND5_MASK    (u32)0x00000200U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_OCM_ISLAND4_MASK    (u32)0x00000100U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_OCM_ISLAND3_MASK    (u32)0x00000080U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_OCM_ISLAND2_MASK    (u32)0x00000040U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_OCM_ISLAND1_MASK    (u32)0x00000020U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_OCM_ISLAND0_MASK    (u32)0x00000010U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_RPU_B_CORE1_MASK    (u32)0x00000008U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_RPU_B_CORE0_MASK    (u32)0x00000004U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_RPU_A_CORE1_MASK    (u32)0x00000002U
#define PSMX_GLOBAL_REG_REQ_PWRUP1_STATUS_RPU_A_CORE0_MASK    (u32)0x00000001U

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRUP1_INT_MASK
 */
#define PSMX_GLOBAL_REG_REQ_PWRUP1_INT_MASK    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000128U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRUP1_INT_EN
 */
#define PSMX_GLOBAL_REG_REQ_PWRUP1_INT_EN    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x0000012CU )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRUP1_INT_DIS
 */
#define PSMX_GLOBAL_REG_REQ_PWRUP1_INT_DIS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000130U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRUP1_TRIG
 */
#define PSMX_GLOBAL_REG_REQ_PWRUP1_TRIG    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000134U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS
 */
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000210U )

#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_FP_MASK    (u32)0x00100000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_L3_3Q_MASK    (u32)0x00080000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_L3_1H_MASK    (u32)0x00040000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_L3_1Q_MASK    (u32)0x00020000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_L3_OFF_MASK    (u32)0x00010000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU3_CORE3_MASK    (u32)0x00008000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU3_CORE2_MASK    (u32)0x00004000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU3_CORE1_MASK    (u32)0x00002000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU3_CORE0_MASK    (u32)0x00001000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU2_CORE3_MASK    (u32)0x00000800U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU2_CORE2_MASK    (u32)0x00000400U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU2_CORE1_MASK    (u32)0x00000200U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU2_CORE0_MASK    (u32)0x00000100U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU1_CORE3_MASK    (u32)0x00000080U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU1_CORE2_MASK    (u32)0x00000040U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU1_CORE1_MASK    (u32)0x00000020U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU1_CORE0_MASK    (u32)0x00000010U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU0_CORE3_MASK    (u32)0x00000008U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU0_CORE2_MASK    (u32)0x00000004U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU0_CORE1_MASK    (u32)0x00000002U
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_STATUS_APU0_CORE0_MASK    (u32)0x00000001U

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRDWN0_INT_MASK
 */
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_INT_MASK    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000214U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRDWN0_INT_EN
 */
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_INT_EN    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000218U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRDWN0_INT_DIS
 */
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_INT_DIS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x0000021CU )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRDWN0_TRIG
 */
#define PSMX_GLOBAL_REG_REQ_PWRDWN0_TRIG    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000220U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS
 */
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000224U )
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_GEM1_MASK    (u32)0x20000000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_GEM0_MASK    (u32)0x10000000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_TCM1B_RET_MASK    (u32)0x08000000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_TCM1A_RET_MASK    (u32)0x04000000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_TCM0B_RET_MASK    (u32)0x02000000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_TCM0A_RET_MASK    (u32)0x01000000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_TCM1B_MASK    (u32)0x00800000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_TCM1A_MASK    (u32)0x00400000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_TCM0B_MASK    (u32)0x00200000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_TCM0A_MASK    (u32)0x00100000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND7_RET_MASK    (u32)0x00080000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND6_RET_MASK    (u32)0x00040000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND5_RET_MASK    (u32)0x00020000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND4_RET_MASK    (u32)0x00010000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND3_RET_MASK    (u32)0x00008000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND2_RET_MASK    (u32)0x00004000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND1_RET_MASK    (u32)0x00002000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND0_RET_MASK    (u32)0x00001000U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND7_MASK    (u32)0x00000800U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND6_MASK    (u32)0x00000400U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND5_MASK    (u32)0x00000200U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND4_MASK    (u32)0x00000100U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND3_MASK    (u32)0x00000080U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND2_MASK    (u32)0x00000040U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND1_MASK    (u32)0x00000020U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_OCM_ISLAND0_MASK    (u32)0x00000010U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_RPU_B_CORE1_MASK    (u32)0x00000008U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_RPU_B_CORE0_MASK    (u32)0x00000004U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_RPU_A_CORE1_MASK    (u32)0x00000002U
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_STATUS_RPU_A_CORE0_MASK    (u32)0x00000001U

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRDWN1_INT_MASK
 */
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_INT_MASK    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000228U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRDWN1_INT_EN
 */
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_INT_EN    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x0000022CU )

/**
 * Register: PSMX_GLOBAL_REG_REQ_PWRDWN1_INT_DIS
 */
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_INT_DIS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000230U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_SWRST_STATUS
 */
#define PSMX_GLOBAL_REG_REQ_SWRST_STATUS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000410U )

/**
 * Register: PSMX_GLOBAL_REG_REQ_SWRST_INT_EN
 */
#define PSMX_GLOBAL_REG_REQ_SWRST_INT_EN    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000418U )

/**
 * Register: PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS
 */
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000600U )

#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_RSVD7_MASK    (u32)0x08000000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_RSVD6_MASK    (u32)0x04000000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_RSVD5_MASK    (u32)0x02000000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_RSVD4_MASK    (u32)0x01000000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_RSVD3_MASK    (u32)0x00800000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_RSVD2_MASK    (u32)0x00400000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_RSVD1_MASK    (u32)0x00200000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_RSVD0_MASK    (u32)0x00100000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU3_CLUSTER_MASK    (u32)0x00080000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU2_CLUSTER_MASK    (u32)0x00040000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU1_CLUSTER_MASK    (u32)0x00020000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU0_CLUSTER_MASK    (u32)0x00010000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU3_CORE3_MASK    (u32)0x00008000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU3_CORE2_MASK    (u32)0x00004000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU3_CORE1_MASK    (u32)0x00002000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU3_CORE0_MASK    (u32)0x00001000U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU2_CORE3_MASK    (u32)0x00000800U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU2_CORE2_MASK    (u32)0x00000400U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU2_CORE1_MASK    (u32)0x00000200U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU2_CORE0_MASK    (u32)0x00000100U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU1_CORE3_MASK    (u32)0x00000080U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU1_CORE2_MASK    (u32)0x00000040U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU1_CORE1_MASK    (u32)0x00000020U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU1_CORE0_MASK    (u32)0x00000010U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU0_CORE3_MASK    (u32)0x00000008U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU0_CORE2_MASK    (u32)0x00000004U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU0_CORE1_MASK    (u32)0x00000002U
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_STATUS_APU0_CORE0_MASK    (u32)0x00000001U

/**
 * Register: PSMX_GLOBAL_REG_WAKEUP0_IRQ_MASK
 */
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_MASK    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000604U )

/**
 * Register: PSMX_GLOBAL_REG_WAKEUP0_IRQ_DIS
 */
#define PSMX_GLOBAL_REG_WAKEUP0_IRQ_DIS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x0000060CU )

/**
 * Register: PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS
 */
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000614U )

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_FPD_DBG_SHIFT   30U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_FPD_DBG_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_FPD_DBG_MASK    (u32)0x40000000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE1_CORESIGHT_SHIFT   29U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE1_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE1_CORESIGHT_MASK    (u32)0x20000000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE0_CORESIGHT_SHIFT   28U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE0_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE0_CORESIGHT_MASK    (u32)0x10000000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE1_CORESIGHT_SHIFT   27U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE1_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE1_CORESIGHT_MASK    (u32)0x08000000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE0_CORESIGHT_SHIFT   26U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE0_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE0_CORESIGHT_MASK    (u32)0x04000000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_DSU_CORESIGHT_SHIFT   25U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_DSU_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_DSU_CORESIGHT_MASK    (u32)0x02000000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_DSU_CORESIGHT_SHIFT   24U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_DSU_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_DSU_CORESIGHT_MASK    (u32)0x01000000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_DSU_CORESIGHT_SHIFT   23U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_DSU_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_DSU_CORESIGHT_MASK    (u32)0x00800000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_DSU_CORESIGHT_SHIFT   22U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_DSU_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_DSU_CORESIGHT_MASK    (u32)0x00400000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE3_CORESIGHT_SHIFT   21U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE3_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE3_CORESIGHT_MASK    (u32)0x00200000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE2_CORESIGHT_SHIFT   20U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE2_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE2_CORESIGHT_MASK    (u32)0x00100000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE1_CORESIGHT_SHIFT   19U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE1_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE1_CORESIGHT_MASK    (u32)0x00080000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE0_CORESIGHT_SHIFT   18U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE0_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU3_CORE0_CORESIGHT_MASK    (u32)0x00040000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE3_CORESIGHT_SHIFT   17U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE3_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE3_CORESIGHT_MASK    (u32)0x00020000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE2_CORESIGHT_SHIFT   16U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE2_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE2_CORESIGHT_MASK    (u32)0x00010000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE1_CORESIGHT_SHIFT   15U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE1_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE1_CORESIGHT_MASK    (u32)0x00008000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE0_CORESIGHT_SHIFT   14U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE0_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU2_CORE0_CORESIGHT_MASK    (u32)0x00004000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE3_CORESIGHT_SHIFT   13U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE3_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE3_CORESIGHT_MASK    (u32)0x00002000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE2_CORESIGHT_SHIFT   12U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE2_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE2_CORESIGHT_MASK    (u32)0x00001000U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE1_CORESIGHT_SHIFT   11U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE1_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE1_CORESIGHT_MASK    (u32)0x00000800U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE0_CORESIGHT_SHIFT   10U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE0_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU1_CORE0_CORESIGHT_MASK    (u32)0x00000400U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE3_CORESIGHT_SHIFT   9U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE3_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE3_CORESIGHT_MASK    (u32)0x00000200U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE2_CORESIGHT_SHIFT   8U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE2_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE2_CORESIGHT_MASK    (u32)0x00000100U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE1_CORESIGHT_SHIFT   7U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE1_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE1_CORESIGHT_MASK    (u32)0x00000080U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE0_CORESIGHT_SHIFT   6U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE0_CORESIGHT_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU0_CORE0_CORESIGHT_MASK    (u32)0x00000040U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE1_SHIFT   5U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE1_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE1_MASK    (u32)0x00000020U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE0_SHIFT   4U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE0_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_B_CORE0_MASK    (u32)0x00000010U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE1_SHIFT   3U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE1_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE1_MASK    (u32)0x00000008U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE0_SHIFT   2U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE0_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_RPU_A_CORE0_MASK    (u32)0x00000004U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU_CLUSTER_DBG_SHIFT   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU_CLUSTER_DBG_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU_CLUSTER_DBG_MASK    (u32)0x00000002U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU_CORE_DBG_SHIFT   0U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU_CORE_DBG_WIDTH   1U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_STATUS_APU_CORE_DBG_MASK    (u32)0x00000001U

/**
 * Register: PSMX_GLOBAL_REG_WAKEUP1_IRQ_MASK
 */
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_MASK    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000618U )

/**
 * Register: PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN
 */
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x0000061CU )

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_FPD_DBG_MASK    (u32)0x40000000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_RPU_B_CORE1_CORESIGHT_MASK    (u32)0x20000000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_RPU_B_CORE0_CORESIGHT_MASK    (u32)0x10000000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_RPU_A_CORE1_CORESIGHT_MASK    (u32)0x08000000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_RPU_A_CORE0_CORESIGHT_MASK    (u32)0x04000000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU3_DSU_CORESIGHT_MASK    (u32)0x02000000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU2_DSU_CORESIGHT_MASK    (u32)0x01000000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU1_DSU_CORESIGHT_MASK    (u32)0x00800000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU0_DSU_CORESIGHT_MASK    (u32)0x00400000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU3_CORE3_CORESIGHT_MASK    (u32)0x00200000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU3_CORE2_CORESIGHT_MASK    (u32)0x00100000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU3_CORE1_CORESIGHT_MASK    (u32)0x00080000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU3_CORE0_CORESIGHT_MASK    (u32)0x00040000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU2_CORE3_CORESIGHT_MASK    (u32)0x00020000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU2_CORE2_CORESIGHT_MASK    (u32)0x00010000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU2_CORE1_CORESIGHT_MASK    (u32)0x00008000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU2_CORE0_CORESIGHT_MASK    (u32)0x00004000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU1_CORE3_CORESIGHT_MASK    (u32)0x00002000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU1_CORE2_CORESIGHT_MASK    (u32)0x00001000U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU1_CORE1_CORESIGHT_MASK    (u32)0x00000800U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU1_CORE0_CORESIGHT_MASK    (u32)0x00000400U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU0_CORE3_CORESIGHT_MASK    (u32)0x00000200U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU0_CORE2_CORESIGHT_MASK    (u32)0x00000100U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU0_CORE1_CORESIGHT_MASK    (u32)0x00000080U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU0_CORE0_CORESIGHT_MASK    (u32)0x00000040U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_RPU_B_CORE1_MASK    (u32)0x00000020U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_RPU_B_CORE0_MASK    (u32)0x00000010U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_RPU_A_CORE1_MASK    (u32)0x00000008U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_RPU_A_CORE0_MASK    (u32)0x00000004U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU_CLUSTER_DBG_MASK    (u32)0x00000002U
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_EN_APU_CORE_DBG_MASK    (u32)0x00000001U

/**
 * Register: PSMX_GLOBAL_REG_WAKEUP1_IRQ_DIS
 */
#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_DIS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000620U )

/**
 * Register: PSMX_GLOBAL_REG_PWR_CTRL0_IRQ_DIS
 */
#define PSMX_GLOBAL_REG_PWR_CTRL0_IRQ_DIS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x0000070CU )
#define PSMX_GLOBAL_REG_PWR_CTRL0_IRQ_DIS_FPD_SUPPLY_MASK    (u32)0x80000000U

/**
 * Register: PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS
 */
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000714U )
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_RPU_B_CORE1_PWRDWN_MASK    (u32)0x00800000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_RPU_B_CORE0_PWRDWN_MASK    (u32)0x00400000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_RPU_A_CORE1_PWRDWN_MASK    (u32)0x00200000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_RPU_A_CORE0_PWRDWN_MASK    (u32)0x00100000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU3_CLUSTER_MASK    (u32)0x00080000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU2_CLUSTER_MASK    (u32)0x00040000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU1_CLUSTER_MASK    (u32)0x00020000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU0_CLUSTER_MASK    (u32)0x00010000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU3_CORE3_PWRDWN_MASK    (u32)0x00008000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU3_CORE2_PWRDWN_MASK    (u32)0x00004000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU3_CORE1_PWRDWN_MASK    (u32)0x00002000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU3_CORE0_PWRDWN_MASK    (u32)0x00001000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU2_CORE3_PWRDWN_MASK    (u32)0x00000800U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU2_CORE2_PWRDWN_MASK    (u32)0x00000400U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU2_CORE1_PWRDWN_MASK    (u32)0x00000200U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU2_CORE0_PWRDWN_MASK    (u32)0x00000100U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU1_CORE3_PWRDWN_MASK    (u32)0x00000080U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU1_CORE2_PWRDWN_MASK    (u32)0x00000040U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU1_CORE1_PWRDWN_MASK    (u32)0x00000020U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU1_CORE0_PWRDWN_MASK    (u32)0x00000010U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU0_CORE3_PWRDWN_MASK    (u32)0x00000008U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU0_CORE2_PWRDWN_MASK    (u32)0x00000004U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU0_CORE1_PWRDWN_MASK    (u32)0x00000002U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_STATUS_APU0_CORE0_PWRDWN_MASK    (u32)0x00000001U

/**
 * Register: PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK
 */
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000718U )
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_RPU_B_CORE1_PWRDWN_MASK    (u32)0x00800000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_RPU_B_CORE0_PWRDWN_MASK    (u32)0x00400000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_RPU_A_CORE1_PWRDWN_MASK    (u32)0x00200000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_RPU_A_CORE0_PWRDWN_MASK    (u32)0x00100000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU3_CLUSTER_MASK    (u32)0x00080000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU2_CLUSTER_MASK    (u32)0x00040000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU1_CLUSTER_MASK    (u32)0x00020000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU0_CLUSTER_MASK    (u32)0x00010000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU3_CORE3_PWRDWN_MASK    (u32)0x00008000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU3_CORE2_PWRDWN_MASK    (u32)0x00004000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU3_CORE1_PWRDWN_MASK    (u32)0x00002000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU3_CORE0_PWRDWN_MASK    (u32)0x00001000U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU2_CORE3_PWRDWN_MASK    (u32)0x00000800U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU2_CORE2_PWRDWN_MASK    (u32)0x00000400U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU2_CORE1_PWRDWN_MASK    (u32)0x00000200U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU2_CORE0_PWRDWN_MASK    (u32)0x00000100U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU1_CORE3_PWRDWN_MASK    (u32)0x00000080U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU1_CORE2_PWRDWN_MASK    (u32)0x00000040U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU1_CORE1_PWRDWN_MASK    (u32)0x00000020U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU1_CORE0_PWRDWN_MASK    (u32)0x00000010U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU0_CORE3_PWRDWN_MASK    (u32)0x00000008U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU0_CORE2_PWRDWN_MASK    (u32)0x00000004U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU0_CORE1_PWRDWN_MASK    (u32)0x00000002U
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_MASK_APU0_CORE0_PWRDWN_MASK    (u32)0x00000001U

/**
 * Register: PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_DIS
 */
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_DIS    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000720U )

/**
 * Register: PSMX_GLOBAL_REG_MEM_CLEAR_TRIGGER
 */
#define PSMX_GLOBAL_REG_MEM_CLEAR_TRIGGER    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000900U )

/**
 * Register: PSMX_GLOBAL_REG_SCAN_CLEAR_TRIGGER
 */
#define PSMX_GLOBAL_REG_SCAN_CLEAR_TRIGGER    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00000920U )

/**
 * Register: PSMX_GLOBAL_REG_PSM_ERR1_TRIG
 */
#define PSMX_GLOBAL_REG_PSM_ERR1_TRIG    ( ( PSMX_GLOBAL_REG_BASEADDR ) + (u32)0x00001020U )
#define PSMX_GLOBAL_REG_PSM_ERR1_TRIG_SRC3_MASK    (u32)0x00000008U

#define PSMX_GLOBAL_REG_WAKEUP1_IRQ_RPU_X_COREX_SHIFT (14U)
#define PSMX_GLOBAL_REG_PWR_CTRL1_IRQ_RPU_X_COREX_SHIFT (4U)
#define PSMX_GLOBAL_REG_REQ_PWRUP1_INT_DIS_RPU_X_COREX_SHIFT (16U)
#define PSMX_GLOBAL_REG_REQ_PWRDWN1_INT_DIS_RPU_X_COREX_SHIFT (16U)
#ifdef __cplusplus
}
#endif

#endif /* XPSMFW_PSMX_GLOBAL_H_ */
