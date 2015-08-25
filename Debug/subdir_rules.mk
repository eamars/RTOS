################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
button.obj: ../button.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" --include_path="C:/Users/rba90/workspace/StellarisWare/utils" --include_path="C:/Users/rba90/workspace/StellarisWare" --include_path="C:/Users/rba90/workspace/StellarisWare/boards/ek-lm3s1968" -g --gcc --define="ccs" --define=PART_LM3S1968 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="button.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

lm3s1968_startup_ccs.obj: ../lm3s1968_startup_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" --include_path="C:/Users/rba90/workspace/StellarisWare/utils" --include_path="C:/Users/rba90/workspace/StellarisWare" --include_path="C:/Users/rba90/workspace/StellarisWare/boards/ek-lm3s1968" -g --gcc --define="ccs" --define=PART_LM3S1968 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="lm3s1968_startup_ccs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" --include_path="C:/Users/rba90/workspace/StellarisWare/utils" --include_path="C:/Users/rba90/workspace/StellarisWare" --include_path="C:/Users/rba90/workspace/StellarisWare/boards/ek-lm3s1968" -g --gcc --define="ccs" --define=PART_LM3S1968 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

rit128x96x4.obj: ../rit128x96x4.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" --include_path="C:/Users/rba90/workspace/StellarisWare/utils" --include_path="C:/Users/rba90/workspace/StellarisWare" --include_path="C:/Users/rba90/workspace/StellarisWare/boards/ek-lm3s1968" -g --gcc --define="ccs" --define=PART_LM3S1968 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="rit128x96x4.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

task.obj: ../task.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" --include_path="C:/Users/rba90/workspace/StellarisWare/utils" --include_path="C:/Users/rba90/workspace/StellarisWare" --include_path="C:/Users/rba90/workspace/StellarisWare/boards/ek-lm3s1968" -g --gcc --define="ccs" --define=PART_LM3S1968 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="task.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


