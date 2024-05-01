#pragma once
#include "physicalController.h"
#include "sensorController.h"

/**
 * Here we do the initalization of how many times the simulation will run,
 * the height of the Water level sensors, and min/max value of the temperature sensors
 */
typedef struct{
    float maxTemperature;
    float minTemperature;
    int criticalPressure;
    int minPressure;
    int maxPressure;
    int tankHeight;
}minMaxValues;


/**
 * Purpose: Initialize The physical Objects
*/
void initializePhysicalMain();

void initializePublic(float waterLevelHeight1, float waterLevelHeight2, float waterLevelHeight3, float waterLevelHeight4,
 float maxTemperature, float minTemperature, float tankHeight,  Heater heater, Valve inlet1, Valve inlet2, Valve outlet);

void getSensorValues();

/**
 * Purpose: Used as the temperature controller. Simply decides what to do with the Heater
*/
void temperatureController(Heater *this, minMaxValues minMax);

/**
 * Data: sensorValuesPackage.pressure - The current reading of the temperature
 * Purpose: Used as the pressure controller. Simply decides what to do with the Outlet valve
 * Post-Condition: The status of the outlet valve changes/stays the same
*/
void pressureController(Valve *this, minMaxValues minMax);

void waterLevelController(Valve *outlet, Valve *inlet1, Valve *inlet2, minMaxValues minMax);
