################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-552961487: ../c2000.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2011/ccs/utils/sysconfig_1.23.0/sysconfig_cli.bat" --script "C:/Users/aguat/Documents/GitHub/Code-Composer-Studio-Projects/TP_CONVERTIDORES_DSP/c2000.syscfg" -o "syscfg" -s "C:/ti/C2000Ware_5_04_00_00/.metadata/sdk.json" -b "/boards/LAUNCHXL_F28379D" --context "CPU1" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-552961487 ../c2000.syscfg
syscfg/board.h: build-552961487
syscfg/board.cmd.genlibs: build-552961487
syscfg/board.opt: build-552961487
syscfg/board.json: build-552961487
syscfg/pinmux.csv: build-552961487
syscfg/epwm.dot: build-552961487
syscfg/adc.dot: build-552961487
syscfg/c2000ware_libraries.cmd.genlibs: build-552961487
syscfg/c2000ware_libraries.opt: build-552961487
syscfg/c2000ware_libraries.c: build-552961487
syscfg/c2000ware_libraries.h: build-552961487
syscfg/clocktree.h: build-552961487
syscfg: build-552961487

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/aguat/Documents/GitHub/Code-Composer-Studio-Projects/TP_CONVERTIDORES_DSP" --include_path="C:/Users/aguat/Documents/GitHub/Code-Composer-Studio-Projects/TP_CONVERTIDORES_DSP/device" --include_path="C:/ti/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/aguat/Documents/GitHub/Code-Composer-Studio-Projects/TP_CONVERTIDORES_DSP/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="C:/Users/aguat/Documents/GitHub/Code-Composer-Studio-Projects/TP_CONVERTIDORES_DSP" --include_path="C:/Users/aguat/Documents/GitHub/Code-Composer-Studio-Projects/TP_CONVERTIDORES_DSP/device" --include_path="C:/ti/C2000Ware_5_04_00_00/driverlib/f2837xd/driverlib/" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/aguat/Documents/GitHub/Code-Composer-Studio-Projects/TP_CONVERTIDORES_DSP/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


