#include "tank.h"
#include <stdio.h>


void initializeTank(Tank *this)
{
    this->pressure = 0;
    this->temperature = 0;
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

void updateTemperature(Tank *this, int isHeaterOn)
{
    if (isHeaterOn)
    {
        this->temperature += 1;
    }
    else
    {
        this->temperature -= 1;
    }

    printf("Updated Temperature: %d\n", this->temperature);
}

void updateWaterLevel(Tank *this, int inlet1Status, int inlet2Status, int outletStatus)
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

    printf("Updated Water Level: %d\n", this->waterLevel);
}

void updatePressure(Tank *this, int outletStatus, int tankHeight, int maxTemperature, int waterLevelSensor3Height, int temperature)
{
    if (this->waterLevel >= waterLevelSensor3Height)
    {
        this->pressure += 5;
    }
    
    if (this ->temperature >= maxTemperature - 10)
    {
        this->pressure += 5;

    }

    if (outletStatus)
    {
        this->pressure -= 5;
        this->waterLevel -= 1;
    }

    printf("Updated Pressure: %d\n", this->pressure);

}