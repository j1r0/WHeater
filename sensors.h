#include <stdbool.h>

/**
 * This might require some sort of semaphore
 */
typedef struct
{
	// The height might be changed to something only the controllers know about
	float waterLevelSensorHeight;
	bool data;
} WaterLevelSensor;

/**
 * Data: height - The height from the bottom of the tank where the sensor will be placed
 * Purpose: Simply acts like a constructor. Call this before doing anything to the sensors
 * Pre-Condition:  WaterLevelSensor is not initialized
 * Post-Condition: A WaterLevelSensor is initialized
 * Returns: Nothing
 */
void initializeWaterLevelSensor(WaterLevelSensor this, float height);

/**
 * Purpose: returns the data read by a WaterLevelSensor to be used by the Controllers
 * Pre-Condition: A WaterLevelSensor exists
 * Post-Condition: Nothing
 * Returns: Nothing
 */
int readWaterLevel(WaterLevelSensor *this);

/**
 * Sensor struct to be used both by the Temperature and Pressure Sensors
 */
typedef struct
{
	int data;
} Sensor;

void initializeSensor(Sensor *this, float value);

float readSensor(Sensor *this);

// How do We update the values of the sensors? 

