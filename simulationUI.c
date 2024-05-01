#include "simulationUI.h"
#include "tank.h"
#include "physicalController.h"
#include "sensorController.h"
#include "mainController.h"
#include <stdio.h>

/**
 * Create instances of the sensors
 */
Sensor pressureSensor;
Sensor temperatureSensor;
WaterLevelSensor waterLevelSensors[4];

Valve inlet1;
Valve inlet2;
Valve outlet;
Heater heater;

minMaxValues minMax;

/**
 * This array contains the heights of the 4 water level sensors
 */
int waterSensorsHeights[4];

/**
 * Instantiate the tank
 */
Tank tank;
/**
 * This array contains the Min and Max of the temperature sensor
 */
float tankHeight;
float criticalPressure;
float maxTemperature;
float minTemperature;

/**
 * This is for the amount of cycles the simulation will be run for
 */
int numOfCycles;
int currentCycle;

void getNumOfCycles()
{
    printf("Select the number of cycles to run the simulation for: \n");
    scanf("%d", &numOfCycles);
    printf("Number of cycles: %d\n", numOfCycles);
}

void setMinMaxTemperature()
{
    float userMaxTemp, userMinTemp;
    printf("Input Maximum temperature in Celsius: \n");
    scanf("%f", &userMaxTemp);

    maxTemperature = userMaxTemp;

    printf("Input Minimum temperature in Celsius: \n");
    scanf("%f", &userMinTemp);

    minTemperature = userMinTemp;
}

void getWaterLevelSensors()
{
    printf("The maximum height of the tank is 20m\n");
    for (int i = 0; i < 4; i++)
    {
        float height;
        printf("Please input height of Water Level Sensor #%d\n", i + 1);
        scanf("%f", &height);
        waterSensorsHeights[i] = height;
    }
}

/**
 * Hardcoding Values for the tank LOL
 */

void initializeValuesTank()
{
    tankHeight = 50;
    criticalPressure = 50;
}

void initializeEverything()
{
    // hardcoded values of the tank
    initializeValuesTank();
    initializeTank(&tank);

    initializePublic(waterSensorsHeights[0], waterSensorsHeights[1], waterSensorsHeights[2],
                     waterSensorsHeights[3], maxTemperature, minTemperature, tankHeight, heater, inlet1, inlet2, outlet, waterLevelSensors, &temperatureSensor, &pressureSensor);
}

void startSimulation()
{
    printf("\n---Starting Simulation---\n");
    for (int i = 0; i < numOfCycles; i++)
    {
        printf("\n---Cycle #%d/%d---\n", i + 1,numOfCycles);
        readTemperature(&temperatureSensor, &tank);
        readPressure(&pressureSensor, &tank);
        readWaterLevel(&waterLevelSensors[0], &tank);
        readWaterLevel(&waterLevelSensors[1], &tank);
        readWaterLevel(&waterLevelSensors[2], &tank);
        readWaterLevel(&waterLevelSensors[3], &tank);

        temperatureController(&heater, temperatureSensor.data);
        waterLevelController(&outlet, &inlet1, &inlet2, tank.waterLevel, waterLevelSensors);
        pressureController(&outlet, tank.pressure);

        printf("\n---Updated Values---\n");
        printf("maxTemperature: %f\n", minMax.maxTemperature);
        updatePressure(&tank, outlet.isOpen, minMax.tankHeight, minMax.maxTemperature, waterLevelSensors[3].data, temperatureSensor.data);
        updateTemperature(&tank, heater.isOn);
        updateWaterLevel(&tank, inlet1.isOpen, inlet2.isOpen, outlet.isOpen);
    }
}
