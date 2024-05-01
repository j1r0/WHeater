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

void initializePhysicalPublic()
{
    initializePhysical(&heater, &inlet1, &inlet2, &outlet);
}

physicalStatusPackage getPhysicalStatus(physicalStatusPackage *currentStatus, Heater *heater, Valve *inlet1, Valve *inlet2, Valve *outlet)
{
    currentStatus->isHeaterOn = heater->isOn;
    currentStatus->isInletOpen1 = inlet1->isOpen;
    currentStatus->isInletOpen2 = inlet2->isOpen;
    currentStatus->isOutletOpen = outlet->isOpen;
    physicalStatusPackage copy = *currentStatus;
    return copy;
}

void setHeaterStatus(Heater *this, bool newStatus)
{
    this->isOn = newStatus;
}

void setValveStatus(Valve *this, bool newStatus)
{
    this->isOpen = newStatus;   
}

