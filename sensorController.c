#include "sensorController.h"
#include <stdio.h>

/**
 * Create instances of the sensors
 */
Sensor pressureSensor;
Sensor temperatureSensor;
SensorsPack sp;
WaterLevelSensor waterLevelSensors[4];


void initializeSensors(SensorsPack *this, float height1, float height2, float height3,float height4)
{
    this->waterLevelSensors[3].height = height4;
    this->waterLevelSensors[2].height = height3;
    this->waterLevelSensors[1].height = height2;
    this->waterLevelSensors[0].height = height1;

    this->waterLevelSensors[3].data = 0;
    this->waterLevelSensors[2].data = 0;
    this->waterLevelSensors[1].data = 0;
    this->waterLevelSensors[0].data = 0;

    this->pressureSensor.data = 0;
    this->temperatureSensor = 0;
}

void initializeSensorsPublic(float height1, float height2, float height3, float height4)
{
    initializeSensors(&sp, temperature, pressure, height1, height2, height3, height4);
}

SensorValues readSensors(SensorValues *this, SensorsPack *sp)
{
    this->waterLevelHigher = getSensorValue(&sp->waterLevelSensor[3]);
    this->waterLevelHigh = getSensorValue(&sp->waterLevelSensor[2]);
    this->waterLevelLow = getSensorValue(&sp->waterLevelSensor[1]);
    this->waterLevelLower = getSensorValue(&sp->waterLevelSensor[0]);

    this->pressure = getSensorValue(&sp->pressureSensor);
    this->temperature = getSensorValue(&sp->temperatureSensor);
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
