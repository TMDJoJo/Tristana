################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Common/Communication/Client.cpp \
../src/Common/Communication/ClientManage.cpp \
../src/Common/Communication/ClientPool.cpp \
../src/Common/Communication/InputBuffer.cpp \
../src/Common/Communication/OutputBuffer.cpp \
../src/Common/Communication/Side.cpp 

OBJS += \
./src/Common/Communication/Client.o \
./src/Common/Communication/ClientManage.o \
./src/Common/Communication/ClientPool.o \
./src/Common/Communication/InputBuffer.o \
./src/Common/Communication/OutputBuffer.o \
./src/Common/Communication/Side.o 

CPP_DEPS += \
./src/Common/Communication/Client.d \
./src/Common/Communication/ClientManage.d \
./src/Common/Communication/ClientPool.d \
./src/Common/Communication/InputBuffer.d \
./src/Common/Communication/OutputBuffer.d \
./src/Common/Communication/Side.d 


# Each subdirectory must supply rules for building sources it contributes
src/Common/Communication/%.o: ../src/Common/Communication/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


