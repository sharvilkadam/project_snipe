################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../jsoncpp/build/debug/CMakeFiles/3.5.1/CompilerIdC/CMakeCCompilerId.c 

OBJS += \
./jsoncpp/build/debug/CMakeFiles/3.5.1/CompilerIdC/CMakeCCompilerId.o 

C_DEPS += \
./jsoncpp/build/debug/CMakeFiles/3.5.1/CompilerIdC/CMakeCCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
jsoncpp/build/debug/CMakeFiles/3.5.1/CompilerIdC/%.o: ../jsoncpp/build/debug/CMakeFiles/3.5.1/CompilerIdC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


