################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Common/Packet/Packet.cpp \
../src/Common/Packet/PacketFactory.cpp 

OBJS += \
./src/Common/Packet/Packet.o \
./src/Common/Packet/PacketFactory.o 

CPP_DEPS += \
./src/Common/Packet/Packet.d \
./src/Common/Packet/PacketFactory.d 


# Each subdirectory must supply rules for building sources it contributes
src/Common/Packet/%.o: ../src/Common/Packet/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


