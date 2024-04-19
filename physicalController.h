#include "physical.h"

/**
 * This is how the Simulation gets the Status of Physical
*/
typedef struct{
    Heater heater;
    Valve inlet1;
    Valve inlet2;
    Valve outlet;
} physicalPackage;

/**
 * Purpose: Acts like a constructor. The heater is initially off
 * Pre-Condition: Heater is not initialized
 * Post-Condition: Heater is off
*/
void initializeHeater(Heater *this);

/**
 * Data: newStatus - status to set the heater to (On/Off)
 * Purpose: To change the status of the Heater
 * Pre-Condition: Heater is initialized
 * Post-Condition: Nothing
 * Returns: Nothing
*/
void setHeaterStatus(Heater *this, bool newStatus);

/**
 * Purpose: Gets the current status of the Heater
 * Pre-Condition: Heater is initialized
 * Post-Condition: Nothing
 * Return: The state of the heater (On/Off)
*/
bool getHeaterStatus(Heater *this);



/**
 * Purpose: Acts like a constructor. The valves are initially off
 * Pre-Condition: Valve is not initialized
 * Post-Condition: Valve is off
*/
void initializeValve(Valve *this);

/**
 * Data: newstatus - status to set the valve to (open/closed)
 * Purpose: To change the status of the Valve
 * Pre-Condition: Valve is initialized
 * Post-Condition: Nothing
 * Returns: Nothing
*/
void setValveStatus(Valve *this, bool newStatus);

/**
 * Purpose: Gets the current status of the Valve
 * Pre-Condition: Valve is initialized
 * Post-Condition: Nothing
 * Return: The state of the Valve (Open/Closed)
*/
bool getValveStatus(Valve *this);