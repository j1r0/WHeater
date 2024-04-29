#include "physicalController.h"
#include <stdio.h>
/**
 * Creating the instances of the Physical objects
 */
physicalStatusPackage currentStatus;

Valve inlet1;
Valve inlet2;
Valve outlet;
Heater heater;

void initializePhysical(Heater *heater, Valve *inlet1, Valve *inlet2, Valve *outlet)
{
    heater->isOn = false;
    inlet1->isOpen = false;
    inlet2->isOpen = false;
    outlet->isOpen = false;
}

physicalStatusPackage getPhysicalStatus(Heater *heater, Valve *inlet1, Valve *inlet2, Valve *outlet)
{
    currentStatus.isHeaterOn = heater->isOn;
}

int main()
{
    
    return 0;
}