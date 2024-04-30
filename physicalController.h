#include <stdbool.h>
#include "physical.h"

/**
 * This is how the Simulation gets the Status of Physical
*/
typedef struct{
    bool isHeaterOn;
    bool isInletOpen1;
    bool isInletOpen2;
    bool isOutletOpen;
} physicalStatusPackage;

/**
 * Purpose: Acts like a constructor. Everything is initially off/Closed
 * Pre-Condition: Everything is initialized
 * Post-Condition: Heater is off, Valves are closed
*/
void initializePhysical(Heater *heater, Valve *inlet1, Valve *inlet2, Valve *outlet);

void initializePhysicalPublic();


/**
 * Purpose: Gets the current status of the Heater
 * Pre-Condition: Heater is initialized
 * Post-Condition: Nothing
 * Return: The state of the heater (On/Off)
*/
physicalStatusPackage getPhysicalStatus(physicalStatusPackage *currentStatus, Heater *heater, Valve *inlet1, Valve *inlet2, Valve *outlet);

/**
 * Data: newStatus - status to set the heater to (On/Off)
 * Purpose: To change the status of the Heater
 * Pre-Condition: Heater is initialized
 * Post-Condition: Nothing
 * Returns: Nothing
*/
void setHeaterStatus(Heater *this, bool newStatus);

/**
 * Data: newstatus - status to set the valve to (open/closed)
 * Purpose: To change the status of the Valve
 * Pre-Condition: Valve is initialized
 * Post-Condition: Nothing
 * Returns: Nothing
*/
void setValveStatus(Valve *this, bool newStatus);