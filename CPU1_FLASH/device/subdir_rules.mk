################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
device/%.obj: ../device/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"H:/ti/CCS11.0.0/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/common/include" --include_path="H:/ti/C2000/C2000Ware_4_00_00_00/device_support/f2837xd/headers/include" --include_path="H:/ti/C2000/C2000Ware_4_00_00_00/libraries/dsp/FPU/c28/examples/common" --include_path="H:/ti/C2000/C2000Ware_4_00_00_00/libraries/dsp/FPU/c28/include/fpu32" --include_path="H:/ti/C2000/C2000Ware_4_00_00_00/libraries/dsp/FPU/c28/include" --include_path="H:/ti/C2000/C2000Ware_4_00_00_00/driverlib/f2837xd/driverlib/" --include_path="H:/ti/C2000/C2000Ware_4_00_00_00/libraries/dsp/FPU/c28/examples/common/f2837xd/" --include_path="{DSP_EXAMPLES_COMMONSRC}/" --include_path="C:/Users/ASUS/Desktop/2021-A/TIworkspace/DIAN_SAI_lanyahou2" --include_path="C:/Users/ASUS/Desktop/2021-A/TIworkspace/DIAN_SAI_lanyahou2/device" --include_path="H:/ti/C2000/C2000Ware_4_00_00_00/driverlib/f2837xs/driverlib" --include_path="H:/ti/CCS11.0.0/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="C:/Users/ASUS/Desktop/2021-A/TIworkspace/DIAN_SAI_lanyahou2" --include_path="C:/Users/ASUS/Desktop/2021-A/TIworkspace/DIAN_SAI_lanyahou2/device" --include_path="H:/ti/C2000/C2000Ware_4_00_00_00/driverlib/f2837xs/driverlib" --include_path="H:/ti/CCS11.0.0/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --advice:performance=all --define=_LAUNCHXL_F28377S --define=DEBUG --define=_FLASH --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="device/$(basename $(<F)).d_raw" --include_path="C:/Users/ASUS/Desktop/2021-A/TIworkspace/DIAN_SAI_lanyahou2/CPU1_FLASH/syscfg" --obj_directory="device" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


