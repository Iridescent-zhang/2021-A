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

#include "board.h"

void Board_init()
{
	EALLOW;

	PinMux_init();
	SCI_init();

	EDIS;
}

void PinMux_init()
{
	//
	// SCIB -> mySCIB Pinmux
	//
	GPIO_setPinConfig(GPIO_87_SCIRXDB);
	GPIO_setPinConfig(GPIO_86_SCITXDB);
	//
	// SCIC -> mySCIC Pinmux
	//
	GPIO_setPinConfig(GPIO_90_SCIRXDC);
	GPIO_setPinConfig(GPIO_89_SCITXDC);

}

void SCI_init(){
	
	//mySCIB initialization
	SCI_clearInterruptStatus(mySCIB_BASE, SCI_INT_RXFF | SCI_INT_TXFF | SCI_INT_FE | SCI_INT_OE | SCI_INT_PE | SCI_INT_RXERR | SCI_INT_RXRDY_BRKDT | SCI_INT_TXRDY);
	SCI_clearOverflowStatus(mySCIB_BASE);

	SCI_disableFIFO(mySCIB_BASE);
	SCI_resetChannels(mySCIB_BASE);

	SCI_setConfig(mySCIB_BASE, DEVICE_LSPCLK_FREQ, mySCIB_BAUDRATE, (SCI_CONFIG_WLEN_8|SCI_CONFIG_STOP_ONE|SCI_CONFIG_PAR_NONE));
	SCI_disableLoopback(mySCIB_BASE);
	SCI_performSoftwareReset(mySCIB_BASE);
	SCI_enableModule(mySCIB_BASE);
	
	//mySCIC initialization
	SCI_clearInterruptStatus(mySCIC_BASE, SCI_INT_RXFF | SCI_INT_TXFF | SCI_INT_FE | SCI_INT_OE | SCI_INT_PE | SCI_INT_RXERR | SCI_INT_RXRDY_BRKDT | SCI_INT_TXRDY);
	SCI_clearOverflowStatus(mySCIC_BASE);

	SCI_disableFIFO(mySCIC_BASE);
	SCI_resetChannels(mySCIC_BASE);

	SCI_setConfig(mySCIC_BASE, DEVICE_LSPCLK_FREQ, mySCIC_BAUDRATE, (SCI_CONFIG_WLEN_8|SCI_CONFIG_STOP_ONE|SCI_CONFIG_PAR_NONE));
	SCI_disableLoopback(mySCIC_BASE);
	SCI_performSoftwareReset(mySCIC_BASE);
	SCI_enableModule(mySCIC_BASE);
}
