################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := H:/ti/CCS11.0.0/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./F2837xD_Adc.obj" \
"./F2837xD_CodeStartBranch.obj" \
"./F2837xD_DefaultISR.obj" \
"./F2837xD_EPwm.obj" \
"./F2837xD_GlobalVariableDefs.obj" \
"./F2837xD_Gpio.obj" \
"./F2837xD_PieCtrl.obj" \
"./F2837xD_PieVect.obj" \
"./F2837xD_SysCtrl.obj" \
"./F2837xD_usDelay.obj" \
"./board.obj" \
"./examples_setup.obj" \
"./sci_ex3_echoback.obj" \
"./device/device.obj" \
"../2837xS_Generic_RAM_lnk.cmd" \
"H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/headers/cmd/F2837xD_Headers_nonBIOS_cpu1.cmd" \
"H:/ti/C2000/C2000Ware_4_00_00_00/driverlib/f2837xs/driverlib/ccs/Debug/driverlib.lib" \
$(GEN_CMDS__FLAG) \
-lc28x_fpu_dsp_library.lib \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include device/subdir_vars.mk
-include subdir_rules.mk
-include device/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
DIAN_SAI_lanyahou2.out \

EXE_OUTPUTS__QUOTED += \
"DIAN_SAI_lanyahou2.out" \

BIN_OUTPUTS += \
DIAN_SAI_lanyahou2.hex \

BIN_OUTPUTS__QUOTED += \
"DIAN_SAI_lanyahou2.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "DIAN_SAI_lanyahou2.out"

# Tool invocations
DIAN_SAI_lanyahou2.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"H:/ti/CCS11.0.0/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --define=_LAUNCHXL_F28377S --define=DEBUG --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"DIAN_SAI_lanyahou2.map" --stack_size=0x100 --warn_sections -i"H:/ti/C2000/C2000Ware_4_00_00_00/libraries/dsp/FPU/c28/lib" -i"H:/ti/CCS11.0.0/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/lib" -i"H:/ti/CCS11.0.0/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="DIAN_SAI_lanyahou2_linkInfo.xml" --entry_point=code_start --rom_model -o "DIAN_SAI_lanyahou2.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

DIAN_SAI_lanyahou2.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: C2000 Hex Utility'
	"H:/ti/CCS11.0.0/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/hex2000" --diag_wrap=off -o "DIAN_SAI_lanyahou2.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "F2837xD_Adc.obj" "F2837xD_CodeStartBranch.obj" "F2837xD_DefaultISR.obj" "F2837xD_EPwm.obj" "F2837xD_GlobalVariableDefs.obj" "F2837xD_Gpio.obj" "F2837xD_PieCtrl.obj" "F2837xD_PieVect.obj" "F2837xD_SysCtrl.obj" "F2837xD_usDelay.obj" "board.obj" "examples_setup.obj" "sci_ex3_echoback.obj" "device\device.obj" 
	-$(RM) "F2837xD_Adc.d" "F2837xD_DefaultISR.d" "F2837xD_EPwm.d" "F2837xD_GlobalVariableDefs.d" "F2837xD_Gpio.d" "F2837xD_PieCtrl.d" "F2837xD_PieVect.d" "F2837xD_SysCtrl.d" "board.d" "examples_setup.d" "sci_ex3_echoback.d" "device\device.d" 
	-$(RM) "F2837xD_CodeStartBranch.d" "F2837xD_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

