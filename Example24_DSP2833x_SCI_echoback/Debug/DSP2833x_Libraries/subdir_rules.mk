################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
DSP2833x_Libraries/%.obj: ../DSP2833x_Libraries/%.asm $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"E:/CCS/CCS9.1.0.00010_win64/setup/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example24_DSP2833x_SCI_echoback/Example24_DSP2833x_SCI_echoback/APP/uart" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example24_DSP2833x_SCI_echoback/Example24_DSP2833x_SCI_echoback/APP/time" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example24_DSP2833x_SCI_echoback/Example24_DSP2833x_SCI_echoback/APP/leds" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="E:/CCS/CCS9.1.0.00010_win64/setup/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="DSP2833x_Libraries/$(basename $(<F)).d_raw" --obj_directory="DSP2833x_Libraries" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DSP2833x_Libraries/%.obj: ../DSP2833x_Libraries/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"E:/CCS/CCS9.1.0.00010_win64/setup/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example24_DSP2833x_SCI_echoback/Example24_DSP2833x_SCI_echoback/APP/uart" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example24_DSP2833x_SCI_echoback/Example24_DSP2833x_SCI_echoback/APP/time" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="E:/CCS/WorkSpace/DSP8233x_ProjectExample/DSP2833x_Example/Example24_DSP2833x_SCI_echoback/Example24_DSP2833x_SCI_echoback/APP/leds" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="E:/CCS/CCS9.1.0.00010_win64/setup/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="DSP2833x_Libraries/$(basename $(<F)).d_raw" --obj_directory="DSP2833x_Libraries" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


