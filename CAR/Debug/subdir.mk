################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MDIO_programe.c \
../MGIE_programe.c \
../MTIMER0_program.c \
../MTIMER2_program.c \
../MUART_program.c \
../main.c 

OBJS += \
./MDIO_programe.o \
./MGIE_programe.o \
./MTIMER0_program.o \
./MTIMER2_program.o \
./MUART_program.o \
./main.o 

C_DEPS += \
./MDIO_programe.d \
./MGIE_programe.d \
./MTIMER0_program.d \
./MTIMER2_program.d \
./MUART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


