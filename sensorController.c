#include "sensorController.h"
#include <stdio.h>


SensorsPack sp;
SensorValues sv;

void initializeSensorsPublic(float height1, float height2, float height3, float height4)
{
    initializeSensors(&sp, height1, height2, height3, height4);
}

void initializeSensors(SensorsPack *this, float height1, float height2, float height3, float height4)
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

    printf("Temperature initialized: %f\n", this->temperatureSensor.data);
    printf("Pressure initialized: %f\n", this->pressureSensor.data);
    printf("WLS1 initialized: %d\n", this->waterLevelSensors[0].data);
    printf("WLS2 initialized: %d\n", this->waterLevelSensors[1].data);
    printf("WLS3 initialized: %d\n", this->waterLevelSensors[2].data);
    printf("WLS4 initialized: %d\n", this->waterLevelSensors[3].data);
    printf("\n");
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
    printf("Reading sensorController WLS1: %d\n", sv.waterLevelLower);
    printf("Reading sensorController WLS2: %d\n", sv.waterLevelLow);
    
    
}

SensorValues readSensorPublic()
{
    return readSensors(&sv, &sp);
}

