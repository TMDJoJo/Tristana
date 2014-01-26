################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Python/PythonScript.cpp \
../src/Python/Template.cpp 

OBJS += \
./src/Python/PythonScript.o \
./src/Python/Template.o 

CPP_DEPS += \
./src/Python/PythonScript.d \
./src/Python/Template.d 


# Each subdirectory must supply rules for building sources it contributes
src/Python/%.o: ../src/Python/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


