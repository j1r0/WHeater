// This file contains the simulated tank and how it calculates its next values
#include <stdbool.h> 

struct tank
{
    int temperature;
    int pressure;
    int waterLevel;
};

// I think this needs like a message queue where once it gets everything it needs
//(pressure, temp, and wlvl) it calculates the new values

// Returns the new temperature for the Temperature sensor to read
// isHeaterOn == 1 for Heater is On
// isHeaterOn == 1 for Heater is Off
int newTemperature(int currentTemp, bool isHeaterOn)
{
    int newTemperature = currentTemp;
    if (isHeaterOn == true)
    {
        newTemperature = newTemperature + 5;
    }
    else
    {
        newTemperature = newTemperature - 5;
    }

    return newTemperature;
}

// Still need to finish this function
int newPressure(int currentPressure, bool isOutValveOpen)
{
    if (isOutValveOpen == true)
    {
        currentPressure = currentPressure - 5;
    }
    else
    {
        currentPressure = currentPressure + 5;
    }
    return currentPressure;
    
}

int newWaterLevel(int currentLevel, bool isOutValveOpen, bool isInlet1Open, bool isInlet2Open)
{
    if (isOutValveOpen == true)
    {
        currentLevel = currentLevel - 5;
    }
    else
    {
        if (isInlet1Open == true)
        {
            currentLevel = currentLevel + 5;
        }
        if (isInlet2Open == true)
        {
            currentLevel = currentLevel + 5;
        }
    }
}