################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jsoncpp.cpp \
../main.cpp \
../videostab.cpp \
../videostabKalman.cpp 

OBJS += \
./jsoncpp.o \
./main.o \
./videostab.o \
./videostabKalman.o 

CPP_DEPS += \
./jsoncpp.d \
./main.d \
./videostab.d \
./videostabKalman.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


