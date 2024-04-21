#include "sensorController.h"
#include <stdio.h>

//MIGHT HAVE TO BE CHANGED IF THE USER CAN INPUT THE INITIAL VALUES although weird
void initializeSensors(SensorsPack *this, float temperature, float pressure, float waterLevel)
{
    this -> waterLevelSensors[3].data = 0;
    this -> waterLevelSensors[2].data = 0;
    this -> waterLevelSensors[1].data = 0;
    this -> waterLevelSensors[0].data = 0;

    this ->pressureSensor.data = 0;
    this ->temperatureSensor = 0;
}

SensorValues readSensors(SensorValues *this, SensorsPack sp)
{
    *this->pressure = getSensorValue(&sp->pressureSensor);
    *this->temperature = getSensorValue(&sp->temperatureSensor);
    *this->waterLevelHigher = getSensorValue(&sp->waterLevelSensor[3]);
    *this->waterLevelHigh = getSensorValue(&sp->waterLevelSensor[2]);
    *this->waterLevelLow = getSensorValue(&sp->waterLevelSensor[1]);
    *this->waterLevelLower = getSensorValue(&sp->waterLevelSensor[0]);
}

/**
 * This shows how you can declare a sensorsPack sp, 
 * and all the sensors in it are declared as well
*/
// int main()
// {
//     // Testing if this works
//     SensorsPack sp;
//     initializeSensors(&sp, 0,0,0);
//     int x = sp.waterLevelSensors[0].data;
//     printf("Data of WLSensor[0]: %d\n", x);
//     // Works :)
//     return 0;
// }