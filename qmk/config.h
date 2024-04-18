// Copyright 2024 
// miketronic@github sepultor@discord -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#pragma once

#    define DEBOUNCE 7
#    define HOLD_ON_OTHER_KEY_PRESS
#    define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#    define TAPPING_TERM 170
#    define COMBO_TERM 150
#    define MACRO_TIMER 3

// Enable rapid switch from tap to hold, setting to 0 disables double tap hold auto-repeat.
#    define QUICK_TAP_TERM 0

#    define SPLIT_USB_DETECT
#    define USE_SERIAL
#    define SERIAL_USART_FULL_DUPLEX
#    define SERIAL_USART_TX_PIN GP28
#    define SERIAL_USART_RX_PIN GP29
#    define SERIAL_USART_PIN_SWAP
#    define MASTER_LEFT

// RGBLIGHT settings
// https://docs.qmk.fm/#/feature_rgblight
#    define WS2812_DI_PIN GP0
#    define WS2812_PIO_USE_PIO1
#    define RGBLIGHT_SPLIT
#    define RGBLED_NUM 28
#    define RGBLED_SPLIT { 14, 14 }
#    define RGBLIGHT_SLEEP

#    undef RGBLIGHT_DEFAULT_HUE
#    define RGBLIGHT_DEFAULT_HUE 43

#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 5

#    undef RGBLIGHT_LIMIT_VAL
#    define RGBLIGHT_LIMIT_VAL 255
#    define RGBLIGHT_DEFAULT_VAL 80
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT

#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_TWINKLE
#    undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#    undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    undef RGBLIGHT_EFFECT_SNAKE
#    undef RGBLIGHT_EFFECT_CHRISTMAS
#    undef RGBLIGHT_EFFECT_ALTERNATING


// SPI
#    define SPI_DRIVER SPID1
#    define SPLIT_POINTING_ENABLE
#    define POINTING_DEVICE_RIGHT
#    define POINTING_DEVICE_CS_PIN GP9
#    define SPI_SCK_PIN GP10
#    define SPI_MISO_PIN GP12
#    define SPI_MOSI_PIN GP11

// PMW3360 settings
//#    define PMW3360_CPI 12000
//#    define PMW3360_CS_DIVISOR 8
//#    define POINTING_DEVICE_TASK_THROTTLE_MS 10
#    define POINTING_DEVICE_ROTATION_180_RIGHT
#    define POINTING_DEVICE_INVERT_X_RIGHT
#    define POINTING_DEVICE_COMBINED
//#    define ROTATIONAL_TRANSFORM_ANGLE 97
//#    define MOUSE_EXTENDED_REPORT

// Mouse key speed and acceleration.
#    undef MOUSEKEY_DELAY
#    define MOUSEKEY_DELAY          0
#    undef MOUSEKEY_INTERVAL
#    define MOUSEKEY_INTERVAL       16
#    undef MOUSEKEY_WHEEL_DELAY
#    define MOUSEKEY_WHEEL_DELAY    0
#    undef MOUSEKEY_MAX_SPEED
#    define MOUSEKEY_MAX_SPEED      6
#    undef MOUSEKEY_TIME_TO_MAX
#    define MOUSEKEY_TIME_TO_MAX    64
