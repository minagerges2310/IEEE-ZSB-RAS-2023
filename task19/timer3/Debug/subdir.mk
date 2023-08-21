################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../DC_program.c \
../DIO_program.c \
../EXTI_program.c \
../GI_program.c \
../KPD_Program.c \
../LCD_program.c \
../Stepper_Motor_program.c \
../TIMERS_program.c \
../WDT_program.c \
../main.c 

OBJS += \
./ADC_program.o \
./DC_program.o \
./DIO_program.o \
./EXTI_program.o \
./GI_program.o \
./KPD_Program.o \
./LCD_program.o \
./Stepper_Motor_program.o \
./TIMERS_program.o \
./WDT_program.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./DC_program.d \
./DIO_program.d \
./EXTI_program.d \
./GI_program.d \
./KPD_Program.d \
./LCD_program.d \
./Stepper_Motor_program.d \
./TIMERS_program.d \
./WDT_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


