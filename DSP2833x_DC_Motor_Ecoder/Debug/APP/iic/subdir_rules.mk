################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
APP/iic/%.obj: ../APP/iic/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"F:/CCS12.3/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/time" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/iic" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/smg" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/pid" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/uart" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/eqep" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/epwm" --include_path="F:/CCS12.3/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/dc_motor" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/key" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/relay" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/leds" --include_path="F:/CCS12.3/CCSProject/DSP2833x_DC_Motor_Ecoder/APP/beep" --include_path="F:/CCS12.3/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="F:/CCS12.3/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="APP/iic/$(basename $(<F)).d_raw" --obj_directory="APP/iic" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


