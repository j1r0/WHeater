#include "mainController.h"
#include "simulationUI.h"
#include "sensorController.h"
#include <stdio.h>

minMaxValues minMax;
SensorValues svMain;



void initializePublic(float waterLevelHeight1, float waterLevelHeight2, float waterLevelHeight3, float waterLevelHeight4, float maxTemperature, float minTemperature,
float tankHeight, Heater heater, Valve inlet1, Valve inlet2, Valve outlet, WaterLevelSensor *waterLevelSensors, Sensor *temperatureSensor, Sensor *pressureSensor)
{
    initializeSensors(waterLevelSensors, temperatureSensor, pressureSensor, waterLevelHeight1, waterLevelHeight2, waterLevelHeight3, waterLevelHeight4);
    initializePhysical(&heater, &inlet1, &inlet2, &outlet);
    minMax.maxTemperature = maxTemperature;
    minMax.minTemperature = minTemperature;
    minMax.tankHeight = tankHeight;
    minMax.criticalPressure = 50;
    minMax.minPressure = 20;
    minMax.maxPressure = 30;
}

void temperatureController(Heater *this, int temperature)
{
    printf("\n---Temperature Controller---\n");
    printf("Temperature: %d\n", temperature);
    if(temperature >= minMax.maxTemperature)
    {
        setHeaterStatus(this, 0);
    } else if (temperature < minMax.maxTemperature)
    {
        setHeaterStatus(this, 1);
    }
    printf("Heater Status: %d\n", this->isOn);
}

void pressureController(Valve *this, int pressure)
{
    printf("\n---Pressure Controller---\n");
    printf("Pressure: %d\n", pressure);
    printf("Critical Pressure: %d\n", minMax.criticalPressure);
    if(pressure >= minMax.criticalPressure)
    {
        setValveStatus(this, 1);
    } else if (pressure < minMax.criticalPressure)
    {
        setValveStatus(this, 0);
    }
    printf("Outlet Valve Status: %d\n", this->isOpen);
}

void waterLevelController(Valve *outlet, Valve *inlet1, Valve *inlet2, int waterLevel, WaterLevelSensor *waterLevelSensors)
{
        printf("\n---Water Level Controller---\n");
    printf("Water Level: %d\n", waterLevel);
    int i;
    for (i = 0; i < 4; i++)
    {
        printf("Water Level Sensor #%d: %d\n", i + 1, waterLevelSensors[i].data);
    }
    if (waterLevelSensors[3].data == 1 || waterLevel > minMax.tankHeight)
    {
        setValveStatus(inlet1, 0);
        setValveStatus(inlet2, 0);
        setValveStatus(outlet, 1); 
        printf("Inlet1 Valve Status: %d\n", inlet1->isOpen);
        printf("Inlet2 Valve Status: %d\n", inlet2->isOpen);
        printf("Outlet Valve Status: %d\n", outlet->isOpen);
    } else if (waterLevelSensors[0].data == 1 || waterLevelSensors[0].data == 0) {
        setValveStatus(inlet1, 1);
        setValveStatus(inlet2, 1);
        setValveStatus(outlet, 0);
        printf("Inlet1 Valve Status: %d\n", inlet1->isOpen);
        printf("Inlet2 Valve Status: %d\n", inlet2->isOpen);
        printf("Outlet Valve Status: %d\n\n", outlet->isOpen);
    }
    

}