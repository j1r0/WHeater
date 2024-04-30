#include "mainController.h"

struct minMaxValues;
SensorValues svMain;

float temperature;
float pressure;
int waterLevelHigher;
int waterLevelHigh;
int waterLevelLow;
int waterLevelLower;

void initializeSensorsMain(float height1, float height2, float height3, float height4)
{
    initializeSensorsPublic(height1, height2, height3, height4);
}

void initializePhysicalMain()
{
    initializePhysicalPublic();
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