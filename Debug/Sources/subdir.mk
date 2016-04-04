################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/BrushlessMotor.c \
../Sources/Events.c \
../Sources/GreiferMotor.c \
../Sources/RTOS.c \
../Sources/SchrittmotorFoerderband.c \
../Sources/SchrittmotorLenkung.c \
../Sources/main.c 

OBJS += \
./Sources/BrushlessMotor.o \
./Sources/Events.o \
./Sources/GreiferMotor.o \
./Sources/RTOS.o \
./Sources/SchrittmotorFoerderband.o \
./Sources/SchrittmotorLenkung.o \
./Sources/main.o 

C_DEPS += \
./Sources/BrushlessMotor.d \
./Sources/Events.d \
./Sources/GreiferMotor.d \
./Sources/RTOS.d \
./Sources/SchrittmotorFoerderband.d \
./Sources/SchrittmotorLenkung.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Klaus Jordan/Desktop/PREN2/PREN/Static_Code/PDD" -I"C:/Users/Klaus Jordan/Desktop/PREN2/PREN/Static_Code/IO_Map" -I"C:/Users/Klaus Jordan/Desktop/PREN2/PREN/Sources" -I"C:/Users/Klaus Jordan/Desktop/PREN2/PREN/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


