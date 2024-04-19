/**
 * This is where we update the values of our simulated tank
*/
#include "physicalController.h"


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
void initializeTank(Tank *this, int temperature, int pressure, int waterLevel);

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

void updateTemperature(Tank *this, bool );