// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
// Tool Version Limit: 2023.10
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xsobel_accel.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XSobel_accel_CfgInitialize(XSobel_accel *InstancePtr, XSobel_accel_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XSobel_accel_Start(XSobel_accel *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_AP_CTRL) & 0x80;
    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XSobel_accel_IsDone(XSobel_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XSobel_accel_IsIdle(XSobel_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XSobel_accel_IsReady(XSobel_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XSobel_accel_EnableAutoRestart(XSobel_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XSobel_accel_DisableAutoRestart(XSobel_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_AP_CTRL, 0);
}

void XSobel_accel_Set_in_r(XSobel_accel *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_IN_R_DATA, (u32)(Data));
    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_IN_R_DATA + 4, (u32)(Data >> 32));
}

u64 XSobel_accel_Get_in_r(XSobel_accel *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_IN_R_DATA);
    Data += (u64)XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_IN_R_DATA + 4) << 32;
    return Data;
}

void XSobel_accel_Set_out_r(XSobel_accel *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_OUT_R_DATA, (u32)(Data));
    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_OUT_R_DATA + 4, (u32)(Data >> 32));
}

u64 XSobel_accel_Get_out_r(XSobel_accel *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_OUT_R_DATA);
    Data += (u64)XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_OUT_R_DATA + 4) << 32;
    return Data;
}

void XSobel_accel_InterruptGlobalEnable(XSobel_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_GIE, 1);
}

void XSobel_accel_InterruptGlobalDisable(XSobel_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_GIE, 0);
}

void XSobel_accel_InterruptEnable(XSobel_accel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_IER);
    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_IER, Register | Mask);
}

void XSobel_accel_InterruptDisable(XSobel_accel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_IER);
    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_IER, Register & (~Mask));
}

void XSobel_accel_InterruptClear(XSobel_accel *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSobel_accel_WriteReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_ISR, Mask);
}

u32 XSobel_accel_InterruptGetEnabled(XSobel_accel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_IER);
}

u32 XSobel_accel_InterruptGetStatus(XSobel_accel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSobel_accel_ReadReg(InstancePtr->Control_BaseAddress, XSOBEL_ACCEL_CONTROL_ADDR_ISR);
}

