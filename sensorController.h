#include "sensors.h"

/**
 * Making a pack of all the sensors, this is how they are all going to be passed to 
 * the Controller Subsystem
 * 
 * Also, this way we just need to declare the sensor pack, and that 
 * declares all of the sensors. See "SensorController.c" main() for example
 * waterLevelSensors[3] = waterLevelHigher
 * waterLevelSensors[2] = waterLevelHigh
 * waterLevelSensors[1] = waterLevelLow
 * waterLevelSensors[0] = waterLevelLower
*/
typedef struct{
    Sensor temperatureSensor;
    Sensor pressureSensor;
    WaterLevelSensor waterLevelSensors[4];
} SensorsPack;

typedef struct sensorValuesPackage{
    float temperature;
    float pressure;
    int waterLevelHigher;
    int waterLevelHigh;
    int waterLevelLow;
    int waterLevelLower;
} SensorValues;

/**
 * Data: value - the intial value of  the sensor (probably 0)
 * Purpose: Simply acts like a constructor. Call this before doing anything to the sensors
 * Pre-Condition:  Sensors are not initialized, but declared
 * Post-Condition: A Sensor is initialized
 * Returns: Nothing
 */
void initializeSensors(SensorsPack *this);


/**
 * Purpose: Reads the values from the sensors and puts them on a 
 * sensorsValue struct to be read by the caller
 * Pre-Condition: Sensors are initialized
 * Post-Condition: Nothing
 * Return: returns SensorValues struct containing the values read from the sensors
*/
SensorValues readSensors(SensorsPack *this);

