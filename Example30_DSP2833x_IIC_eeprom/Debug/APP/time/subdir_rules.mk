################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
APP/time/%.obj: ../APP/time/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"E:/CCS/CCS9.1.0.00010_win64/setup/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example30_DSP2833x_IIC_eeprom/APP/iic" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example30_DSP2833x_IIC_eeprom/APP/24cxx" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example30_DSP2833x_IIC_eeprom/APP/spi" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example30_DSP2833x_IIC_eeprom/APP/uart" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example30_DSP2833x_IIC_eeprom/APP/time" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example30_DSP2833x_IIC_eeprom/APP/smg" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example30_DSP2833x_IIC_eeprom/APP/key" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example30_DSP2833x_IIC_eeprom/APP/leds" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="E:/CCS/CCS9.1.0.00010_win64/setup/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="APP/time/$(basename $(<F)).d_raw" --obj_directory="APP/time" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


