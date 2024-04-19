#include <stdbool.h>
// Struct for the heater, with 2 functions, one to set the status of the heater,
// and another one to get the status of the heater

typedef struct
{
    bool isOn;
} Heater;
/**
 * Purpose: Acts like a contructor. The heater is initially off
 * Pre-Condition: Heater is not initialized
 * Post-Condition: Heater is off
 */
void initializeHeater(Heater *this);

// We could Either do toggle or set. Toggle simply switches the isOn attribute.
// while set you choose what you want to set it to

/**
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
 * Struct for the Valves. Works for both the inlets and outlet
 */

typedef struct
{
    bool isOpen;
} Valve;

/**
 * Purpose: Acts like a contructor. The valves are initially off
 * Pre-Condition: Valve is not initialized
 * Post-Condition: Valve is off
 */
void initializeValve(Valve *this);

/**
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