#include "tank.h"
#include <stdio.h>


void initializeTank(Tank *this)
{
    this->pressure = 0;
    this->temperature = 70;
    this->waterLevel = 10;
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
        this->temperature += 5;
    }
    else
    {
        while (this->temperature > 70)
        {
            printf("Regulating Temperature: %d\n", this->temperature);
            if (this->temperature >= 5){
            this->temperature -= 5;
        } else {
            this->temperature = 0;
        }
        }
    }

    printf("\nUpdated Temperature: %d\n", this->temperature);
}

void updateWaterLevel(Tank *this, int inlet1Status, int inlet2Status, int outletStatus, int waterLevelSensor1Height)
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
        printf("\n");
       while (this -> waterLevel > waterLevelSensor1Height)
        {
            printf("Decreasing Water Level: %d\n", this->waterLevel);
            printf("Decreasing Pressure as water level decreases: %d\n", this->pressure);
            this->waterLevel -= 1;
            if (this-> pressure >= 2){
            this->pressure -= 2;
        } else {
            this->pressure = 0;
        }
        }
    }

    printf("Updated Water Level: %d\n", this->waterLevel);
}

void updatePressure(Tank *this, int outletStatus, int tankHeight, int maxTemperature, int temperature, int waterLevelSensor3Height, int waterLevelSensor1Height)
{

    if (outletStatus)
    {
        
        while (this -> waterLevel > waterLevelSensor1Height || this->pressure >= 50)
        {
            printf("Decreasing Water Level due to pressure: %d\n", this->waterLevel);
            printf("Decreasing Pressure: %d\n", this->pressure);
            if (this -> waterLevel >= 1)
            {
            this->waterLevel -= 1;
            } else {
                this->waterLevel = 1;
            }
            if (this-> pressure >= 2){
            this->pressure -= 2;
        } else {
            this->pressure = 0;
        }
        }

    } else {
    if (this->waterLevel >= waterLevelSensor3Height)
    {
        this->pressure += 5;
    }
    
    if (this ->temperature >= maxTemperature - 10)
    {
        this->pressure += 5;

    }
}

    printf("\nUpdated Pressure: %d\n", this->pressure);

}