################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jsoncpp/src/jsontestrunner/main.cpp 

OBJS += \
./jsoncpp/src/jsontestrunner/main.o 

CPP_DEPS += \
./jsoncpp/src/jsontestrunner/main.d 


# Each subdirectory must supply rules for building sources it contributes
jsoncpp/src/jsontestrunner/%.o: ../jsoncpp/src/jsontestrunner/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


