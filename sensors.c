#include "sensors.h"

void initializeSensor(Sensor *this, float value)
{
    this->data = value;
}

float readSensor(Sensor *this)
{
    return this->data;
}