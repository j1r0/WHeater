#pragma once
/**
 * This is where we update the values of our simulated tank
*/



typedef struct {
    int temperature;
    int pressure;
    int waterLevel;
} Tank;

/**
 * Data: initial parameters of the tank (Probably set to 0)
 * Purpose: Simply acts like a constructor
 * Pre-Condition: The tank is not initialized
 * Post-Condition: The tank is initialized
*/
void initializeTank(Tank *this);


/**
 * Purpose: Gets the temperature of the tank
 * Return: Temperature of the tank
*/
int getTemperature(Tank *this);

/**
 * Purpose: Gets the Temperature of the tank
 * Return: Temperature of the tank
*/
int getPressure(Tank *this);

/**
 * Purpose: Gets the waterLevel of the tank
 * Pre-condition: Water Tank is initialized
 * Return: waterLevel of the tank
*/
int getWaterLevel(Tank *this);

/**
 * Data: isHeaterOn - status of the Heater
 * Purpose: Does the calculations to update the temperature of the tank
 * Pre-condition: Water Tank is initialized
 * Return: Nothing
*/
void updateTemperature(Tank *this, int isHeaterOn);

/**
 * Data: inletstatus - status of the inlet
 *       outletstatus - status of the outlet
 * Purpose: Does the calculations to update the water level of the tank
 * Pre-condition: Water Tank is initialized
 * Return: Nothing
*/
void updateWaterLevel(Tank *this, int inlet1Status, int inlet2Status, int outletStatus, int waterlevelSensor1Height);

/**Data: Requires some conditions, idk
 * Purpose: Update the pressure value of the tank
*/
void updatePressure(Tank *this, int outletStatus, int tankHeight, int maxTemperature, int temperature, int waterLevelSensor3Height, int waterLevelSensor1Height);
