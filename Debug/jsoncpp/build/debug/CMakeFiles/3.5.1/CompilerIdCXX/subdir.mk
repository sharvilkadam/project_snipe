################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jsoncpp/build/debug/CMakeFiles/3.5.1/CompilerIdCXX/CMakeCXXCompilerId.cpp 

OBJS += \
./jsoncpp/build/debug/CMakeFiles/3.5.1/CompilerIdCXX/CMakeCXXCompilerId.o 

CPP_DEPS += \
./jsoncpp/build/debug/CMakeFiles/3.5.1/CompilerIdCXX/CMakeCXXCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
jsoncpp/build/debug/CMakeFiles/3.5.1/CompilerIdCXX/%.o: ../jsoncpp/build/debug/CMakeFiles/3.5.1/CompilerIdCXX/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


