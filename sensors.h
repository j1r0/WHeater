#include <stdbool.h>

/**
 * Sensor struct to be used All sensors.
 * Water Level Sensors read either 0 (off) or 1 (on)
 */
typedef struct
{
	int data;
} Sensor;

/**
 * Data: value - the intial value of  the sensor (probably 0)
 * Purpose: Simply acts like a constructor. Call this before doing anything to the sensors
 * Pre-Condition:  Sensors are not initialized, but declared
 * Post-Condition: A Sensor is initialized
 * Returns: Nothing
 */
void initializeSensor(Sensor *this, float value);

float readSensor(Sensor *this);

// How do We update the values of the sensors?
