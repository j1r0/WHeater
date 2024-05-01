#include "mainController.h"
#include <stdio.h>

minMaxValues minMax;

SensorValues svMain;

float temperature;
float pressure;
int waterLevelHigher;
int waterLevelHigh;
int waterLevelLow;
int waterLevelLower;

void initializePhysicalMain()
{
    initializePhysicalPublic();
}

void initializePublic(float waterLevelHeight1, float waterLevelHeight2, float waterLevelHeight3, float waterLevelHeight4, float maxTemperature, float minTemperature,
float tankHeight)
{
    initializeSensorsPublic(waterLevelHeight1, waterLevelHeight2, waterLevelHeight3, 
    waterLevelHeight4);
    initializePhysicalPublic();

    minMax.maxTemperature = maxTemperature;
    minMax.minTemperature = minTemperature;
    minMax.tankHeight = tankHeight;

    //Hardcoded values of the tank
    minMax.criticalPressure = 50;
    minMax.minPressure = 20;
    minMax.maxPressure = 30;
}



void getSensorValues()
{
    SensorValues svMain = readSensorPublic();
    pressure = svMain.pressure;
    temperature = svMain.temperature;
    waterLevelLower = svMain.waterLevelLower;
    waterLevelLow = svMain.waterLevelLow;
    waterLevelHigh = svMain.waterLevelHigh;
    waterLevelHigher = svMain.waterLevelHigher;

    printf("Temperature from sensor: %f\n", svMain.temperature);
    printf("Pressure from sensor: %f\n", svMain.pressure);
    printf("waterLevelLower from sensor: %d\n", svMain.waterLevelLower);
    printf("waterLevelLow from sensor: %d\n", svMain.waterLevelLow);
    printf("waterLevelHigh from sensor: %d\n", svMain.waterLevelHigh);
    printf("waterLevelHigher from sensor: %d\n", svMain.waterLevelHigher);

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

void pressureController(Valve *this, minMaxValues minMax)
{
    if(pressure >= minMax.criticalPressure)
    {
        setValveStatus(this, true);
    }
}

void waterLevelController(Valve *outlet, Valve *inlet1, Valve *inlet2, minMaxValues minMax)
{
    // NEED TO IMPLEMENT THIS
};