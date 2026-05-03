################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_tiny_fill_disabled.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_small_round_disabled.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_active.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_disabled.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small_active.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_highlight_off_25_25_E8F6FB.svg.cpp 

OBJS += \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_tiny_fill_disabled.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_small_round_disabled.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_active.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_disabled.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small_active.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_highlight_off_25_25_E8F6FB.svg.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_tiny_fill_disabled.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_small_round_disabled.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_active.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_disabled.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small_active.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_highlight_off_25_25_E8F6FB.svg.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/__generated/%.o TouchGFX/generated/images/src/__generated/%.su TouchGFX/generated/images/src/__generated/%.cyclo: ../TouchGFX/generated/images/src/__generated/%.cpp TouchGFX/generated/images/src/__generated/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated:
	-$(RM) ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_tiny_fill_disabled.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_tiny_fill_disabled.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_tiny_fill_disabled.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_tiny_fill_disabled.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_small_round_disabled.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_small_round_disabled.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_small_round_disabled.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_small_round_disabled.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_active.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_active.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_active.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_active.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_disabled.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_disabled.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_disabled.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_disabled.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small_active.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small_active.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small_active.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_imageprogress_styled_batteries_battery_small_active.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_highlight_off_25_25_E8F6FB.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_highlight_off_25_25_E8F6FB.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_highlight_off_25_25_E8F6FB.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_highlight_off_25_25_E8F6FB.svg.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated

