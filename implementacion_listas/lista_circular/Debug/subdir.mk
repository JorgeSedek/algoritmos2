################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lista_circular.cpp \
../main.cpp \
../nodo.cpp 

CPP_DEPS += \
./lista_circular.d \
./main.d \
./nodo.d 

OBJS += \
./lista_circular.o \
./main.o \
./nodo.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./lista_circular.d ./lista_circular.o ./main.d ./main.o ./nodo.d ./nodo.o

.PHONY: clean--2e-

