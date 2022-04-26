################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../2837xS_Generic_FLASH_lnk.cmd \
H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/headers/cmd/F2837xD_Headers_nonBIOS_cpu1.cmd 

LIB_SRCS += \
H:/ti/C2000/C2000Ware_4_00_00_00/driverlib/f2837xs/driverlib/ccs/Debug/driverlib.lib 

ASM_SRCS += \
H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_CodeStartBranch.asm \
H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_usDelay.asm 

C_SRCS += \
H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Adc.c \
H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_DefaultISR.c \
H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_EPwm.c \
../F2837xD_GlobalVariableDefs.c \
H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Gpio.c \
H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_PieCtrl.c \
H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_PieVect.c \
H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_SysCtrl.c \
../board.c \
H:/ti/C2000/C2000Ware_4_00_00_00/libraries/dsp/FPU/c28/examples/common/examples_setup.c \
../sci_ex3_echoback.c 

C_DEPS += \
./F2837xD_Adc.d \
./F2837xD_DefaultISR.d \
./F2837xD_EPwm.d \
./F2837xD_GlobalVariableDefs.d \
./F2837xD_Gpio.d \
./F2837xD_PieCtrl.d \
./F2837xD_PieVect.d \
./F2837xD_SysCtrl.d \
./board.d \
./examples_setup.d \
./sci_ex3_echoback.d 

OBJS += \
./F2837xD_Adc.obj \
./F2837xD_CodeStartBranch.obj \
./F2837xD_DefaultISR.obj \
./F2837xD_EPwm.obj \
./F2837xD_GlobalVariableDefs.obj \
./F2837xD_Gpio.obj \
./F2837xD_PieCtrl.obj \
./F2837xD_PieVect.obj \
./F2837xD_SysCtrl.obj \
./F2837xD_usDelay.obj \
./board.obj \
./examples_setup.obj \
./sci_ex3_echoback.obj 

ASM_DEPS += \
./F2837xD_CodeStartBranch.d \
./F2837xD_usDelay.d 

OBJS__QUOTED += \
"F2837xD_Adc.obj" \
"F2837xD_CodeStartBranch.obj" \
"F2837xD_DefaultISR.obj" \
"F2837xD_EPwm.obj" \
"F2837xD_GlobalVariableDefs.obj" \
"F2837xD_Gpio.obj" \
"F2837xD_PieCtrl.obj" \
"F2837xD_PieVect.obj" \
"F2837xD_SysCtrl.obj" \
"F2837xD_usDelay.obj" \
"board.obj" \
"examples_setup.obj" \
"sci_ex3_echoback.obj" 

C_DEPS__QUOTED += \
"F2837xD_Adc.d" \
"F2837xD_DefaultISR.d" \
"F2837xD_EPwm.d" \
"F2837xD_GlobalVariableDefs.d" \
"F2837xD_Gpio.d" \
"F2837xD_PieCtrl.d" \
"F2837xD_PieVect.d" \
"F2837xD_SysCtrl.d" \
"board.d" \
"examples_setup.d" \
"sci_ex3_echoback.d" 

ASM_DEPS__QUOTED += \
"F2837xD_CodeStartBranch.d" \
"F2837xD_usDelay.d" 

C_SRCS__QUOTED += \
"H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Adc.c" \
"H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_DefaultISR.c" \
"H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_EPwm.c" \
"../F2837xD_GlobalVariableDefs.c" \
"H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Gpio.c" \
"H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_PieCtrl.c" \
"H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_PieVect.c" \
"H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_SysCtrl.c" \
"../board.c" \
"H:/ti/C2000/C2000Ware_4_00_00_00/libraries/dsp/FPU/c28/examples/common/examples_setup.c" \
"../sci_ex3_echoback.c" 

ASM_SRCS__QUOTED += \
"H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_CodeStartBranch.asm" \
"H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_usDelay.asm" 


