#include "sensorController.h"
#include <stdio.h>

/**
 * Create instances of the sensors
 */
Sensor pressureSensor;
Sensor temperatureSensor;
WaterLevelSensor waterLevelSensors[4];

SensorsPack sp;
SensorValues sv;

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
    this->temperatureSensor.data = 0;
}

void initializeSensorsPublic(float height1, float height2, float height3, float height4)
{
    initializeSensors(&sp, height1, height2, height3, height4);
}

SensorValues readSensors(SensorValues *this, SensorsPack *sp)
{
    this->waterLevelHigher = getWaterLevelSensorValue(&(sp->waterLevelSensors[3]));
    this->waterLevelHigh = getWaterLevelSensorValue(&(sp->waterLevelSensors[2]));
    this->waterLevelLow = getWaterLevelSensorValue(&(sp->waterLevelSensors[1]));
    this->waterLevelLower = getWaterLevelSensorValue(&(sp->waterLevelSensors[0]));

    this->pressure = getSensorValue(&(sp->pressureSensor));
    this->temperature = getSensorValue(&(sp->temperatureSensor));

    SensorValues sv = *this;
}

SensorValues readSensorPublic()
{
    return readSensors(&sv, &sp);
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
