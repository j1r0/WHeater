#include "sensors.h"

void initializeWaterLevelSensor(WaterLevelSensor *this, float height)
{
    this->data = false;
    this->waterLevelSensorHeight = height;
}

int readWaterLevel(WaterLevelSensor *this)
{
    return this->data;
}

void initializeSensor(Sensor *this, float value)
{
    this->data = value;
}

int readSensor(Sensor *this)
{
    return this->data;
}