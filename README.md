# Stm32 LVLG Plant Watering Station

Stm32 based project started to gain experience with LVGL library.

Uses common stm32f411ceu6 (blackpill) board, ILI9341 2.8" resisitve touch display module toghether with custom PCB.

## Features

- Screen backlight dimming
- Two independent plant channels with separate PWM controlled pump outputs and  moisture sensors
- Parameters for each plan channel are indepentent of each other.
- Unused plant channel can be disabled.
- Date, time kept even after disconnecting power thanks to cr2032 and stm32 embedded clock
- Settable time window in which pump can operate in order for the device to not become annoying or waking up anyone at night
- Whole process controlled using touch screen input only