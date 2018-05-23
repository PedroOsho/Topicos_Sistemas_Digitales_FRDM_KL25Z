################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/pin_mux.c 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/pin_mux.o 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -DCR_INTEGER_PRINTF -DFREEDOM -DFRDM_KL25Z -DDEBUG -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -I"C:\Users\PEDRO\Desktop\proyectos\FRDM\MCUXpressoIDE_10.1.1_606\Topicos_Sistemas_Digitales\frdmkl25z_driver_examples_gpio_led_output\board" -I"C:\Users\PEDRO\Desktop\proyectos\FRDM\MCUXpressoIDE_10.1.1_606\Topicos_Sistemas_Digitales\frdmkl25z_driver_examples_gpio_led_output\source" -I"C:\Users\PEDRO\Desktop\proyectos\FRDM\MCUXpressoIDE_10.1.1_606\Topicos_Sistemas_Digitales\frdmkl25z_driver_examples_gpio_led_output" -I"C:\Users\PEDRO\Desktop\proyectos\FRDM\MCUXpressoIDE_10.1.1_606\Topicos_Sistemas_Digitales\frdmkl25z_driver_examples_gpio_led_output\drivers" -I"C:\Users\PEDRO\Desktop\proyectos\FRDM\MCUXpressoIDE_10.1.1_606\Topicos_Sistemas_Digitales\frdmkl25z_driver_examples_gpio_led_output\utilities" -I"C:\Users\PEDRO\Desktop\proyectos\FRDM\MCUXpressoIDE_10.1.1_606\Topicos_Sistemas_Digitales\frdmkl25z_driver_examples_gpio_led_output\CMSIS" -I"C:\Users\PEDRO\Desktop\proyectos\FRDM\MCUXpressoIDE_10.1.1_606\Topicos_Sistemas_Digitales\frdmkl25z_driver_examples_gpio_led_output\startup" -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


