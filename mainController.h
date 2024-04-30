#pragma once
#include "physicalController.h"
#include "sensorController.h"
#include "simulationUI.h"

/**
 * Data: Height of the different sensors (lowest height to tallest)
 *      We might need an algorithm to determine which height is for which sensor
 *      Also, 2 sensors cannot have the same height
 * Purpose: initialize water level sensor's heights
 * WE NEED TO KNOW HOW TALL TANK WILL BE
*/
void initializeSensorsMain(float height1, float height2, float height3, float height4);

/**
 * Purpose: Initialize The physical Objects
*/
void initializePhysicalMain();

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
