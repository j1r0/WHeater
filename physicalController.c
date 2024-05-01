#include "physicalController.h"
#include "mainController.h"
#include <stdio.h>

/**
 * Creating the instances of the Physical objects
 */
physicalStatusPackage currentStatus;




void initializePhysical(Heater *heater, Valve *inlet1, Valve *inlet2, Valve *outlet)
{
    heater->isOn = 0;
    inlet1->isOpen = 0;
    inlet2->isOpen = 0;
    outlet->isOpen = 0;
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

void setHeaterStatus(Heater *this, int newStatus)
{
    this->isOn = newStatus;
}

void setValveStatus(Valve *this, int newStatus)
{
    this->isOpen = newStatus;   
}