################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Common/Communication/Socket/ActiveSocket.cpp \
../src/Common/Communication/Socket/PassiveSocket.cpp \
../src/Common/Communication/Socket/SimpleSocket.cpp 

OBJS += \
./src/Common/Communication/Socket/ActiveSocket.o \
./src/Common/Communication/Socket/PassiveSocket.o \
./src/Common/Communication/Socket/SimpleSocket.o 

CPP_DEPS += \
./src/Common/Communication/Socket/ActiveSocket.d \
./src/Common/Communication/Socket/PassiveSocket.d \
./src/Common/Communication/Socket/SimpleSocket.d 


# Each subdirectory must supply rules for building sources it contributes
src/Common/Communication/Socket/%.o: ../src/Common/Communication/Socket/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


