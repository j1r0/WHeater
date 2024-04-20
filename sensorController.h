#include "sensors.h"

/**
 * This struct wraps a water level sensor into a data type only available to the 
 * Sensor controller. This way the Sensor controller can assign each sensor a height, 
 * without the sensors having to know their height, only reading
 * 
 * Basically takes away from the sensor a job that shouldnt be theirs
*/
typedef struct{
    float height;
    Sensor waterLevelSensor;
} WaterLevelControllerWrap;

/**
 * Making a pack of all the sensors, this is how they are all going to be passed to 
 * the Controller Subsystem
*/
typedef struct{
    Sensor temperatureSensor;
    Sensor pressureSensor;
    Sensor waterLevelSensors[4];
} SensorsPack;


/**
 * Declare the sensors used by the Controller
*/
Sensor temperatureSensor;
Sensor pressureSensor;
Sensor waterLevelSensors[4];

Sensor waterLevelSensorHigher;
Sensor waterLevelSensorHigh;
Sensor waterLevelSensorLow;
Sensor waterLevelSensorLower;

/**
 * Data: value - the intial value of  the sensor (probably 0)
 * Purpose: Simply acts like a constructor. Call this before doing anything to the sensors
 * Pre-Condition:  Sensors are not initialized, but declared
 * Post-Condition: A Sensor is initialized
 * Returns: Nothing
 */
void initializeSensor(Sensor *this, float value);



