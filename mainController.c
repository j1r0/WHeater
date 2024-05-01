#include "mainController.h"
#include "simulationUI.h"
#include "sensorController.h"
#include <stdio.h>

minMaxValues minMax;

SensorValues svMain;

int waterLevelHigher;
int waterLevelHigh;
int waterLevelLow;
int waterLevelLower;



void initializePublic(float waterLevelHeight1, float waterLevelHeight2, float waterLevelHeight3, float waterLevelHeight4, float maxTemperature, float minTemperature,
float tankHeight, Heater heater, Valve inlet1, Valve inlet2, Valve outlet)
{
    initializeSensorsPublic(waterLevelHeight1, waterLevelHeight2, waterLevelHeight3, 
    waterLevelHeight4);
    initializePhysical(&heater, &inlet1, &inlet2, &outlet);

    minMax.maxTemperature = maxTemperature;
    minMax.minTemperature = minTemperature;
    minMax.tankHeight = tankHeight;

    //Hardcoded values of the tank
    minMax.criticalPressure = 50;
    minMax.minPressure = 20;
    minMax.maxPressure = 30;
}

void temperatureController(Heater *this, minMaxValues minMax, int temperature)
{
    if(temperature >= minMax.maxTemperature)
    {
        setHeaterStatus(this, false);
    } else if (temperature <= minMax.minTemperature)
    {
        setHeaterStatus(this, true);
    }
}

void pressureController(Valve *this, minMaxValues minMax, int pressure)
{
    if(pressure >= minMax.criticalPressure)
    {
        setValveStatus(this, true);
    }
}

void waterLevelController(Valve *outlet, Valve *inlet1, Valve *inlet2, minMaxValues minMax, int waterLevel)
{
    if (waterLevelHigher == 1 || waterLevel > minMax.tankHeight)
    {
        setValveStatus(inlet1, false);
        setValveStatus(inlet2, false);
        setValveStatus(outlet, true);
    } else if (waterLevelHigh == 1)
    {
        setValveStatus(inlet1, true);
        setValveStatus(inlet2, false);
        setValveStatus(outlet, false);
    } else if (waterLevelLow == 1 || waterLevelLower == 1 || waterLevelLower == 0)
    {
        setValveStatus(inlet1, true);
        setValveStatus(inlet2, true);
        setValveStatus(outlet, false);
    }

};