################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../utilities/uart_comm.cpp 

OBJS += \
./utilities/uart_comm.o 

CPP_DEPS += \
./utilities/uart_comm.d 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.cpp utilities/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


