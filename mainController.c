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


void getSensorValues()
{
    SensorValues svMain = readSensorPublic();
    pressure = svMain.pressure;
    temperature = svMain.temperature;
    waterLevelLower = svMain.waterLevelLower;
    waterLevelLow = svMain.waterLevelLow;
    waterLevelHigh = svMain.waterLevelHigh;
    waterLevelHigher = svMain.waterLevelHigher;

    // printf("Temperature from sensor: %f\n", svMain.temperature);
    // printf("Pressure from sensor: %f\n", svMain.pressure);
    // printf("waterLevelLower from sensor: %d\n", svMain.waterLevelLower);
    // printf("waterLevelLow from sensor: %d\n", svMain.waterLevelLow);
    // printf("waterLevelHigh from sensor: %d\n", svMain.waterLevelHigh);
    // printf("waterLevelHigher from sensor: %d\n", svMain.waterLevelHigher);

}

void temperatureController(Heater *this, minMaxValues minMax)
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