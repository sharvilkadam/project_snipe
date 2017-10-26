################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jsoncpp/build/debug/CMakeFiles/CheckTypeSize/LCONV_SIZE.cpp 

OBJS += \
./jsoncpp/build/debug/CMakeFiles/CheckTypeSize/LCONV_SIZE.o 

CPP_DEPS += \
./jsoncpp/build/debug/CMakeFiles/CheckTypeSize/LCONV_SIZE.d 


# Each subdirectory must supply rules for building sources it contributes
jsoncpp/build/debug/CMakeFiles/CheckTypeSize/%.o: ../jsoncpp/build/debug/CMakeFiles/CheckTypeSize/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


