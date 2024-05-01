
/**
 * This is where we update the values of our simulated tank
*/

#include <stdbool.h>



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
void updateTemperature(Tank *this, bool isHeaterOn);

/**
 * Data: inletstatus - status of the inlet
 *       outletstatus - status of the outlet
 * Purpose: Does the calculations to update the water level of the tank
 * Pre-condition: Water Tank is initialized
 * Return: Nothing
*/
void updateWaterLevel(Tank *this, bool inlet1Status, bool inlet2Status, bool outletStatus);

/**Data: Requires some conditions, idk
 * Purpose: Update the pressure value of the tank
*/
void updatePressure(Tank *this, bool outletStatus, int tankHeight, int maxTemperature);