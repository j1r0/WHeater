#include "sensorController.h"
#include <stdio.h>


SensorValues sv;

void initializeSensors(WaterLevelSensor *waterLevelSensors, Sensor *temperatureSensor, Sensor *pressureSensor, float height1, float height2, float height3, float height4)
{
    waterLevelSensors[0].height = height1;
    waterLevelSensors[1].height = height2;
    waterLevelSensors[2].height = height3;
    waterLevelSensors[3].height = height4;

    waterLevelSensors[3].data = 0;
    waterLevelSensors[2].data = 0;
    waterLevelSensors[1].data = 0;
    waterLevelSensors[0].data = 0;

    pressureSensor->data = 0; 
    temperatureSensor->data = 0;
}

// SensorValues readSensors(SensorValues *this, SensorsPack *sp)
// {
//     this->waterLevelHigher = getWaterLevelSensorValue(&(sp->waterLevelSensors[3]));
//     this->waterLevelHigh = getWaterLevelSensorValue(&(sp->waterLevelSensors[2]));
//     this->waterLevelLow = getWaterLevelSensorValue(&(sp->waterLevelSensors[1]));
//     this->waterLevelLower = getWaterLevelSensorValue(&(sp->waterLevelSensors[0]));

//     this->pressure = getSensorValue(&(sp->pressureSensor));
//     this->temperature = getSensorValue(&(sp->temperatureSensor));

//     SensorValues sv = *this;
//     printf("Reading sensorController WLS1: %d\n", sv.waterLevelLower);
//     printf("Reading sensorController WLS2: %d\n", sv.waterLevelLow);
//     printf("Reading TemperatureController Temp: %f\n", sp->temperatureSensor.data);
    
//     return sv;
// }
