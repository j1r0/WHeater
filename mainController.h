/**
 * *********************** DELETE THIS LATER ******************
*/
// #include "simulationUI.h" 
// #include "sensorController.h"
// #include "physical.h"
/**************************************/

/**
 * Forward Declaration - min and max values from Simulation.h
*/
struct minMaxValues;

/**
 * Forward Declaration - Sensor Values is defined in sensorController.h
*/
struct SensorValues;


/**
 * Forward Declaration - Both defined in physical.h
*/
struct Heater;
struct Valve;

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

/**
 * Purpose: Used as the temperature controller. Simply decides what to do with the Heater
*/
void temperatureController(Heater *this, minMaxValues minMax);

/**
 * Data: sensorValuesPackage.pressure - The current reading of the temperature
 * Purpose: Used as the pressure controller. Simply decides what to do with the Outlet valve
 * Post-Condition: The status of the outlet valve changes/stays the same
*/
void pressureController();

void waterLevelController();