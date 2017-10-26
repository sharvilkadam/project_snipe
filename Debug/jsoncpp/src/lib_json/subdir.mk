################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jsoncpp/src/lib_json/json_reader.cpp \
../jsoncpp/src/lib_json/json_value.cpp \
../jsoncpp/src/lib_json/json_writer.cpp 

OBJS += \
./jsoncpp/src/lib_json/json_reader.o \
./jsoncpp/src/lib_json/json_value.o \
./jsoncpp/src/lib_json/json_writer.o 

CPP_DEPS += \
./jsoncpp/src/lib_json/json_reader.d \
./jsoncpp/src/lib_json/json_value.d \
./jsoncpp/src/lib_json/json_writer.d 


# Each subdirectory must supply rules for building sources it contributes
jsoncpp/src/lib_json/%.o: ../jsoncpp/src/lib_json/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


