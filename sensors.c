#include "sensors.h"

void readPressure(Sensor *this, Tank *tank)
{
    this->data = tank->pressure;
}

void readTemperature(Sensor *this, Tank *tank)
{
    this->data = tank->temperature;
}

void readWaterLevel(WaterLevelSensor *this, Tank *tank)
{
    // If the waterLevel < sensor, sensor is off
    if (tank->waterLevel < *this->height )
    {
        this->data = 0;
    } else
    {
        this->data = 1;
    }
}

int getSensorValue(Sensor *this)
{
    return this->data;
}

int getWaterLevelSensorValue(WaterLevelSensor *this)
{
    return this->data;
}
