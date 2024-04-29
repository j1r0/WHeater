#include "physical.h"

void initializeHeater(Heater *this)
{
    this->isOn = false;
}

void toggleHeaterStatus(Heater *this, bool newStatus)
{
    this->isOn = newStatus;
}

bool getHeaterStatus(Heater *this)
{
    return this->isOn;
}

void initializeValve(Valve *this)
{
    this->isOpen = false;
}

void toggleValveStatus(Valve *this, bool newStatus)
{
    this->isOpen = newStatus;
}

bool getValveStatus(Valve *this)
{
    return this->isOpen;
}

