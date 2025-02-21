/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */

#define MASTER_LEFT // windows
// #define MASTER_RIGHT // macos

#define USE_SERIAL

#define TAPPING_TERM 175

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

// Mouse key speed and acceleration. Using acceleration mode (default)
#define MOUSEKEY_DELAY               10 // Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL            20 // Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA           4 // Step size
#define MOUSEKEY_MAX_SPEED           10 // Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX         30 // Time until maximum cursor speed is reached
#define MOUSEKEY_WHEEL_DELAY         10 // Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL      80 // Time between wheel movements
#define MOUSEKEY_WHEEL_DELTA          1 // Wheel movement step size
#define MOUSEKEY_WHEEL_MAX_SPEED      8 // Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX   40 // Time until maximum scroll speed is reached

// remove debug to save filesize
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

// RGB color modes
//#ifdef RGB_MATRIX_ENABLE
//  #define ENABLE_RGB_MATRIX_ALPHAS_MODS
//  #define ENABLE_RGB_MATRIX_BREATHING
//  #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
//  #define ENABLE_RGB_MATRIX_FLOWER_BLOOMING
//  #define ENABLE_RGB_MATRIX_SPLASH
//endif
