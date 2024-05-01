#pragma once
#include <stdbool.h>

/**
 * Struct for the Heater
*/
typedef struct
{
    bool isOn;
} Heater;


/**
 * Struct for the Valves. Works for both the inlets and outlet
 */
typedef struct
{
    bool isOpen;
} Valve;
