/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

#define GPIO_PIN_SCIRXDB 87
#define GPIO_PIN_SCITXDB 86
#define GPIO_PIN_SCIRXDC 90
#define GPIO_PIN_SCITXDC 89

#define mySCIB_BASE SCIB_BASE
#define mySCIB_BAUDRATE 9600
#define mySCIB_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define mySCIB_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define mySCIB_CONFIG_PAR SCI_CONFIG_PAR_NONE
#define mySCIC_BASE SCIC_BASE
#define mySCIC_BAUDRATE 115200
#define mySCIC_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define mySCIC_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define mySCIC_CONFIG_PAR SCI_CONFIG_PAR_NONE

void	Board_init();
void	SCI_init();
void	PinMux_init();

#endif  // end of BOARD_H definition
