#include <stdbool.h>
// #include "tankSim.h"

/**
 * Sensor struct to be used All sensors.
 * Water Level Sensors read either 0 (off) or 1 (on)
 */
typedef struct
{
	int data;
} Sensor; 

/**
 * Purpose: Reads the data from the sensor
 * Pre-Condition: Sensor is initialized
 * Post-Condition: Nothing
 * Return: Value read by the sensor
*/
float readSensor(Sensor *this);

/**
 * Purpose: Reads the data from the Water Level sensor
 * Pre-Condition: Water Level Sensor is initialized
 * Post-Condition: Nothing
 * Return: Whether the sensor is on or not
*/
bool readWaterLevelSensor(Sensor *this);

// Fuck how do I upload tank here
// void updateSensor(Sensor *this, Tank *stank);
// How do We update the values of the sensors?
