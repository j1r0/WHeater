#include "mainController.h"
#include "simulationUI.h"
#include "sensorController.h"
#include <stdio.h>

minMaxValues minMax;
SensorValues svMain;



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

void temperatureController(Heater *this, int temperature)
{

    printf("Temperature: %d\n", temperature);
    printf("Max Temp: %f\n", minMax.maxTemperature);
    if(temperature >= minMax.maxTemperature)
    {
        setHeaterStatus(this, false);
    } else if (temperature < minMax.minTemperature)
    {
        setHeaterStatus(this, true);
    }
    printf("Heater Status: %d\n", this->isOn);
}

void pressureController(Valve *this, int pressure)
{
    if(pressure >= minMax.criticalPressure)
    {
        setValveStatus(this, true);
    }
}

void waterLevelController(Valve *outlet, Valve *inlet1, Valve *inlet2, int waterLevel, WaterLevelSensor *waterLevelSensors)
{
    for (int i = 0; i < 4; i++)
    {
        printf("WLS %d: %d\n", i+1, waterLevelSensors[i].data);
    }
    if (waterLevelSensors[3].data == 1 || waterLevel > minMax.tankHeight)
    {
        setValveStatus(inlet1, false);
        setValveStatus(inlet2, false);
        setValveStatus(outlet, true); 
    } else if (waterLevelSensors[0].data == 1) {
        setValveStatus(inlet1, true);
        setValveStatus(inlet2, true);
        setValveStatus(outlet, false);
    }

}