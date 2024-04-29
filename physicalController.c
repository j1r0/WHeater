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

int main()
{
    physicalStatusPackage copy;
    initializePhysical(&heater, &inlet1, &inlet2, &outlet);
    copy = getPhysicalStatus(&currentStatus, &heater, &inlet1, &inlet2, &outlet);
    copy.isHeaterOn = false;
    if (currentStatus.isHeaterOn)
    {
        printf("Heater is on!\n");
    }
    else
    {
        printf("Heater is off :c\n");
    }
    return 0;
}

