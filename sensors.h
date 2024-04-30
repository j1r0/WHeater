#include <stdbool.h>
#include "tank.h"

/**
 * Sensor struct to be used All sensors.
 */
typedef struct 
{
	float data;
}Sensor; 

/**
 * I wanted to have the WLS to not know its height, but then we have no way
 * of knowing whether it can detect the water or not (bc its a simulation)
 * 
 * Data - 0 for Off, 1 for On
 * Height - the height from the bottom of the tank
*/
typedef struct
{
	float height;
	int data;
} WaterLevelSensor;

/**
 * Purpose: Reads the emperature from the tank, and updates the sensor
 * Pre-Condition: Sensor is initialized
 * Post-Condition: Nothing
 * Return: Nothing
*/
void readTemperature(Sensor *this, Tank *tank);


/**
 * Purpose: Reads the pressure from the tank, and updates the sensor
 * Pre-Condition: Sensor is initialized
 * Post-Condition: Nothing
 * Return: Nothing
*/
void readPressure(Sensor *this, Tank *tank);


/**
 * Purpose: Reads the water level from the tank, and updates the sensor
 * Pre-Condition: Water Level Sensor is initialized
 * Post-Condition: Nothing
 * Return: Nothing
*/
void readWaterLevel(WaterLevelSensor *this, Tank *tank);

/**
 * Purpose: Reads the value from the sensors
 * Pre-Condition: Sensor is initialized
 * Post-Condition: Nothing
 * Return: Value read by sensor
*/
int getSensorValue(Sensor *this);
/**
 * Purpose: Reads the value from the sensors
 * Pre-Condition: Water Level Sensor is initialized
 * Post-Condition: Nothing
 * Return: Value read by sensor
*/
int getWaterLevelSensorValue(WaterLevelSensor *this);
