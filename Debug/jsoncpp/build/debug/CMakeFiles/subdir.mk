################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../jsoncpp/build/debug/CMakeFiles/feature_tests.cxx 

C_SRCS += \
../jsoncpp/build/debug/CMakeFiles/feature_tests.c 

OBJS += \
./jsoncpp/build/debug/CMakeFiles/feature_tests.o 

CXX_DEPS += \
./jsoncpp/build/debug/CMakeFiles/feature_tests.d 

C_DEPS += \
./jsoncpp/build/debug/CMakeFiles/feature_tests.d 


# Each subdirectory must supply rules for building sources it contributes
jsoncpp/build/debug/CMakeFiles/%.o: ../jsoncpp/build/debug/CMakeFiles/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

jsoncpp/build/debug/CMakeFiles/%.o: ../jsoncpp/build/debug/CMakeFiles/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


