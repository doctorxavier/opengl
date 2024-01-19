################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cube.c \
../fog.c \
../funciones.c \
../ground.c \
../image.c \
../lights.c \
../principal.c \
../sphere.c 

OBJS += \
./cube.o \
./fog.o \
./funciones.o \
./ground.o \
./image.o \
./lights.o \
./principal.o \
./sphere.o 

C_DEPS += \
./cube.d \
./fog.d \
./funciones.d \
./ground.d \
./image.d \
./lights.d \
./principal.d \
./sphere.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


