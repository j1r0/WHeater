#include "tank.h"


void initializeTank(Tank *this)
{
    this->pressure = 0;
    this->temperature = 20;
    this->waterLevel = 0;
}

int getPressure(Tank *this)
{
    return this->pressure;
}

int getTemperature(Tank *this)
{
    return this->temperature;
}
int getWaterLevel(Tank *this)
{
    return this->waterLevel;
}

void updateTemperature(Tank *this, bool isHeaterOn)
{
    if (isHeaterOn)
    {
        this->temperature += 1;
    }
    else
    {
        this->temperature -= 1;
    }
}

void updateWaterLevel(Tank *this, bool inlet1Status, bool inlet2Status, bool outletStatus)
{
    if (inlet1Status)
    {
        this->waterLevel += 1;
    }
    if (inlet2Status)
    {
        this->waterLevel += 1;
    }
    if (outletStatus)
    {
        this->waterLevel -= 1;
    }
}

void updatePressure(Tank *this, bool outletStatus, int tankHeight, int maxTemperature)
{
    if (this->waterLevel >= tankHeight -10)
    {
        this->pressure += 5;
    }
    if (this ->temperature > maxTemperature - 10)
    {
        this->pressure += 5;
    }

    if (outletStatus)
    {
        this->pressure -= 5;
    }

}