//#############################################################################
//
// FILE:   sci_ex3_echoback.c
//
// TITLE:  SCI echoback example.
//
//! \addtogroup driver_example_list
//! <h1>SCI Echoback</h1>
//!
//!  This test receives and echo-backs data through the SCI-A port.
//!
//!  A terminal such as 'putty' can be used to view the data from
//!  the SCI and to send information to the SCI. Characters received
//!  by the SCI port are sent back to the host.
//!
//!  \b Running \b the \b Application
//!  Open a COM port with the following settings using a terminal:
//!  -  Find correct COM port
//!  -  Bits per second = 9600
//!  -  Data Bits = 8
//!  -  Parity = None
//!  -  Stop Bits = 1
//!  -  Hardware Control = None
//!
//!  The program will print out a greeting and then ask you to
//!  enter a character which it will echo back to the terminal.
//!
//!  \b Watch \b Variables \n
//!  - loopCounter - the number of characters sent
//!
//! \b External \b Connections \n
//!  Connect the SCI-A port to a PC via a USB cable.
//!  Refer to the hardware user guide for the UART/USB connector information.
//
//#############################################################################
//
// $Release Date:  $
// $Copyright:
// Copyright (C) 2014-2021 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "driverlib.h"
#include "device.h"

#include "fpu_rfft.h"
//#include "fpu_cfft.h"
#include "math.h"
#include "examples_setup.h"

#include "board.h"

#include "string.h"
#include "board.h"
#include "stdio.h"
#include "math.h"

/********************
 * FFT DEFINENATIONS
 ********************/
#define RFFT_STAGES     10
#define RFFT_SIZE       (1 << RFFT_STAGES)
#define  NUM_OF_DRAW  100
#define  NUM_OF_DRAW_WIFI  60

// DECLAIRE VAR
RFFT_F32_STRUCT rfft;
RFFT_F32_STRUCT_Handle hnd_rfft = &rfft;
RFFT_ADC_F32_STRUCT rfft_adc;
RFFT_ADC_F32_STRUCT_Handle hnd_rfft_adc = &rfft_adc;
uint16_t RFFTin1Buff[2*RFFT_SIZE];          // RFFT IN
float RFFToutBuff[RFFT_SIZE];           // RFFT OUT
float RFFTmagBuff[RFFT_SIZE/2+1];       // RFFT MAGNITUDE
float RFFTphaseBuff[RFFT_SIZE/2];       // RFFT PHASE
float RFFTF32Coef[RFFT_SIZE];           // RFFT COEFFENCES

// DECLAIRE RAMSPACE
#pragma DATA_SECTION(RFFTin1Buff,"RFFTdata1")
#pragma DATA_SECTION(RFFToutBuff,"RFFTdata2")
#pragma DATA_SECTION(RFFTmagBuff,"RFFTdata3")
#pragma DATA_SECTION(RFFTphaseBuff,"RFFTdata4")
#pragma DATA_SECTION(RFFTF32Coef,"RFFTdata5")


/********************
 * ADC DEFINENATIONS
 ********************/
//  PA0
#define RESULTS_BUFFER_SIZE     (10240)
#define ADC_EPWM_BASE           1000  //100M/AD_EPWM_BASE
#define ADC_EPWM_COMP           (ADC_EPWM_BASE+1)/2
uint16_t adcAResults[RESULTS_BUFFER_SIZE];   // Buffer for results
uint16_t index;                              // Index into result buffer
volatile uint16_t bufferFull;                // Flag to indicate buffer is full
#pragma DATA_SECTION(adcAResults,"adcAResultsdata");
//
// Function Prototypes
void initADC(void);
void getADC(void);
void initEPWM(void);
void initADCSOC(void);
__interrupt void adcA1ISR(void);
__interrupt void dmach1ISR(void);
void wifi_send(void);

/********************
 * UART DEFINENATIONS
 ********************/
char * msg, *str, *strmsg, *msg_wifi;
uint16_t val = 586 ,len;
uint16_t i,j;
float f[5],THD;
uint16_t wifi_uint16[6];
float   gui2, gui3, gui4, gui5;
uint8_t val2,val3,val4,val5;
uint16_t val_THD;
uint16_t wifi_data[NUM_OF_DRAW_WIFI];

/*************************
 *  DRAW PTS DEFINATION
 ************************/
uint8_t npts[NUM_OF_DRAW];


#define max(a,b) a>b?a:b
//
// Main
//
void main(void)
{

#ifdef FLASH
    EALLOW;
    Flash0EccRegs.ECC_ENABLE.bit.ENABLE = 0;
    memcpy((uint32_t *)&RamfuncsRunStart, (uint32_t *)&RamfuncsLoadStart,
            (uint32_t)&RamfuncsLoadSize );
    FPU_initFlash();
#ifdef USE_TABLES
    memcpy((uint32_t *)&FFTTwiddlesRunStart, (uint32_t *)&FFTTwiddlesLoadStart,
            (uint32_t)&FFTTwiddlesLoadSize );
#endif //USE_TABLES
#endif //FLASH
//    char * msg;
//    msg = "\r\n\n\nHello World!\0";
//    SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, 17);
    FPU_initSystemClocks();

        Device_init();
        Device_initGPIO();
        Board_init();

        Interrupt_initModule();
        FPU_initEpie();


/***************
 * ADC BEGIN
 ***************/
        Interrupt_register(INT_ADCA1, &adcA1ISR);
        initADC();
        initEPWM();
        initADCSOC();
        // Initialize results buffer
        for(index = 0; index < RESULTS_BUFFER_SIZE; index++)
        {
            adcAResults[index] = 0;
        }
        index = 0;
        bufferFull = 0;
        // Enable ADC interrupt
        Interrupt_enable(INT_ADCA1);
        // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
        EINT;
        ERTM;
        getADC();


/*********************
 *  RFFT BEGINE
 *********************/
    // Clear input buffers:
    hnd_rfft_adc->Tail = &(hnd_rfft->OutBuf);
    hnd_rfft->FFTSize   = RFFT_SIZE;
    hnd_rfft->FFTStages = RFFT_STAGES;
    hnd_rfft_adc->InBuf = &RFFTin1Buff[0];  //Input buffer
    hnd_rfft->OutBuf    = &RFFToutBuff[0];  //Output buffer
    hnd_rfft->MagBuf    = &RFFTmagBuff[0];  //Magnitude buffer
    hnd_rfft->PhaseBuf  = &RFFTphaseBuff[0];
    hnd_rfft->CosSinBuf = &RFFTF32Coef[0];  //Twiddle factor buffer
    RFFT_f32_sincostable(hnd_rfft);         //Calculate twiddle factor

/***************
 * RFFT END
 ***************/
       getADC();
       for(i=0; i < RFFT_SIZE; i++)
       {
           RFFTin1Buff[i] = adcAResults[i];
       }
       for (i=0; i < RFFT_SIZE; i++)
       {
             RFFToutBuff[i] = 0;
       }

       for (i=0; i <= RFFT_SIZE/2; i++)
       {
            RFFTmagBuff[i] = 0;
       }
       RFFT_adc_f32(hnd_rfft_adc);
       RFFT_f32_mag_TMU0(hnd_rfft);
       RFFT_f32_phase_TMU0(hnd_rfft);

       for(i=0;i<5;i++)
                  f[i] = 0;

                       for(i=1;i<6;i++)
                       {
                           for(j=i*10-2;j<=i*10+2;j++)
                           {
                               f[i-1] = (f[i-1]>RFFTmagBuff[j])?f[i-1]:RFFTmagBuff[j];
                           }
                       }

       THD = sqrt(f[1]*f[1]+f[2]*f[2]+f[3]*f[3]+f[4]*f[4])/f[0];
                if(THD>=0.1)
                    val_THD = THD*1000;
                else if(THD>0 & THD<0.1)
                    val_THD = THD*1000;
                gui2 = f[1]/f[0];
                gui3 = f[2]/f[0];
                gui4 = f[3]/f[0];
                gui5 = f[4]/f[0];
                val2 = gui2*1000;
                val3 = gui3*1000;
                val4 = gui4*1000;
                val5 = gui5*1000;

      len = sprintf(msg, "cle 12,0\xff\xff\xff");
      SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, len);

      len = sprintf(msg, "x0.val=%d\xff\xff\xff", val2);  //把整数val打印成一个字符串保存在s中
      SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, len);
      len = sprintf(msg, "x1.val=%d\xff\xff\xff", val3);  //把整数val打印成一个字符串保存在s中
      SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, len);
      len = sprintf(msg, "x2.val=%d\xff\xff\xff", val4);  //把整数val打印成一个字符串保存在s中
      SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, len);
      len = sprintf(msg, "x3.val=%d\xff\xff\xff", val5);  //把整数val打印成一个字符串保存在s中
      SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, len);
      len = sprintf(msg, "x4.val=%d\xff\xff\xff", val_THD);  //把整数val打印成一个字符串保存在s中
      SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, len);


      for(i=1 ;i<NUM_OF_DRAW ;i++) {
          len = sprintf(msg, "add 12,0,%d\xff\xff\xff",(uint8_t)(adcAResults[i]/16));  //把整数val打印成一个字符串保存在s中  原来写的(uint16_t)(adcAResults[i]/8))好像错了
          SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, len);
          SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, len);
          SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, len);
          SCI_writeCharArray(mySCIB_BASE, (uint16_t*)msg, len);
      }

      wifi_uint16[0] = val_THD;
      wifi_uint16[1] = 1000;
      wifi_uint16[2] = val2;
      wifi_uint16[3] = val3;
      wifi_uint16[4] = val4;
      wifi_uint16[5] = val5;

      int k=0;
      for(i=0;i<=100;i++) {
          wifi_data[k++] = (uint16_t)(adcAResults[i]/8);
          i = k*1.6;
          if(k>=60)
              break;
      }
      wifi_send();

      while(1)
      {

      }
}

void wifi_send(void) {
    len = sprintf(msg_wifi, "0x55");
    SCI_writeCharArray(mySCIC_BASE, (uint16_t*)msg_wifi, len);
    DELAY_US(15000);

    len = sprintf(msg_wifi, "%d", 60);
    SCI_writeCharArray(mySCIC_BASE, (uint16_t*)msg_wifi, len);
        DELAY_US(15000);

        for(i=0; i<=5 ;i++) {
            len = sprintf(msg_wifi, "%d", wifi_uint16[i]);
            SCI_writeCharArray(mySCIC_BASE, (uint16_t*)msg_wifi, len);
                        DELAY_US(15000);
        }

        for(i=0; i < NUM_OF_DRAW_WIFI ;i++) {
            len = sprintf(msg_wifi, "%d", wifi_data[i]);
            SCI_writeCharArray(mySCIC_BASE, (uint16_t*)msg_wifi, len);
            DELAY_US(15000);
                }

        len = sprintf(msg_wifi, "0xaa");
                SCI_writeCharArray(mySCIC_BASE, (uint16_t*)msg_wifi, len);
                DELAY_US(15000);

}

void getADC()
{
    // Start ePWM1, enabling SOCA and putting the counter in up-count mode
    //
    EPWM_enableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);

    //
    // Wait while ePWM1 causes ADC conversions which then cause interrupts.
    // When the results buffer is filled, the bufferFull flag will be set.
    //
    while(bufferFull == 0)
    {
    }
    bufferFull = 0;     // Clear the buffer full flag

    //
    // Stop ePWM1, disabling SOCA and freezing the counter
    //
    EPWM_disableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);

    //
    // Software breakpoint. At this point, conversion results are stored in
    // adcAResults.

}

void initADC(void)
{

    //
    // Set ADCDLK divider to /4
    //
    ADC_setPrescaler(ADCA_BASE, ADC_CLK_DIV_4_0);

    //
    // Set resolution and signal mode (see #defines above) and load
    // corresponding trims.
    //

    ADC_setMode(ADCA_BASE, ADC_RESOLUTION_12BIT, ADC_MODE_SINGLE_ENDED);

    //
    // Set pulse positions to late
    //
    ADC_setInterruptPulseMode(ADCA_BASE, ADC_PULSE_END_OF_CONV);

    //
    // Power up the ADC and then delay for 1 ms
    //
    ADC_enableConverter(ADCA_BASE);
    DEVICE_DELAY_US(1000);
}

//
// Function to configure ePWM1 to generate the SOC.
//
void initEPWM(void)
{
    //
    // Disable SOCA
    //
    EPWM_disableADCTrigger(EPWM1_BASE, EPWM_SOC_A);

    //
    // Configure the SOC to occur on the first up-count event
    //
    EPWM_setADCTriggerSource(EPWM1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_U_CMPA);
    EPWM_setADCTriggerEventPrescale(EPWM1_BASE, EPWM_SOC_A, 1);

    //
    // Set the compare A value to 1000 and the period to 1999
    // Assuming ePWM clock is 100MHz, this would give 50kHz sampling
    // 50MHz ePWM clock would give 25kHz sampling, etc.
    // The sample rate can also be modulated by changing the ePWM period
    // directly (ensure that the compare A value is less than the period).
    //
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, ADC_EPWM_COMP);
    EPWM_setTimeBasePeriod(EPWM1_BASE, ADC_EPWM_BASE);

    //
    // Set the local ePWM module clock divider to /1
    //
    EPWM_setClockPrescaler(EPWM1_BASE,
                           EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    //
    // Freeze the counter
    //
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);
}

//
// Function to configure ADCA's SOC0 to be triggered by ePWM1.
//
void initADCSOC(void)
{
    //
    // Configure SOC0 of ADCA to convert pin A0. The EPWM1SOCA signal will be
    // the trigger.
    // - For 12-bit resolution, a sampling window of 15 (75 ns at a 200MHz
    //   SYSCLK rate) will be used.  For 16-bit resolution, a sampling window
    //   of 64 (320 ns at a 200MHz SYSCLK rate) will be used.
    // - NOTE: A longer sampling window will be required if the ADC driving
    //   source is less than ideal (an ideal source would be a high bandwidth
    //   op-amp with a small series resistance). See TI application report
    //   SPRACT6 for guidance on ADC driver design.
    //

    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA,
                 ADC_CH_ADCIN0, 15);

    //
    // Set SOC0 to set the interrupt 1 flag. Enable the interrupt and make
    // sure its flag is cleared.
    //
    ADC_setInterruptSource(ADCA_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER0);
    ADC_enableInterrupt(ADCA_BASE, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);
}

//
// ADC A Interrupt 1 ISR
//
__interrupt void adcA1ISR(void)
{
    //
    // Add the latest result to the buffer
    //
    adcAResults[index++] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);

    //
    // Set the bufferFull flag if the buffer is full
    //
    if(RESULTS_BUFFER_SIZE <= index)
    {
        index = 0;
        bufferFull = 1;
    }

    //
    // Clear the interrupt flag
    //
    ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);

    //
    // Check if overflow has occurred
    //
    if(true == ADC_getInterruptOverflowStatus(ADCA_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(ADCA_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);
    }

    //
    // Acknowledge the interrupt
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}
//
// End of File
//

