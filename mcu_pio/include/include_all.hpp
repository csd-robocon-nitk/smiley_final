#pragma once

// libraries
#include <Arduino.h>
#include <vector>
#include <Wire.h>
#include <Adafruit_BNO055.h>
#include <MDLib.h>
#include "blitz.hpp"
#include "blitz_timer.cpp"
#include "stdlib.h"

// constants (and pinmap)
#include "constants/constants.hpp"

// functions
#include "functions/store_data.cpp"
#include "functions/timer_cb.cpp"
#include "functions/CalculateMotorVelocities.cpp"
#include "functions/SetMotorSpeed.cpp"
#include "functions/Encoders.cpp"