################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jsoncpp/src/test_lib_json/jsontest.cpp \
../jsoncpp/src/test_lib_json/main.cpp 

OBJS += \
./jsoncpp/src/test_lib_json/jsontest.o \
./jsoncpp/src/test_lib_json/main.o 

CPP_DEPS += \
./jsoncpp/src/test_lib_json/jsontest.d \
./jsoncpp/src/test_lib_json/main.d 


# Each subdirectory must supply rules for building sources it contributes
jsoncpp/src/test_lib_json/%.o: ../jsoncpp/src/test_lib_json/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


