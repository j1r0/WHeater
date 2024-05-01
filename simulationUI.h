#pragma once
#include <stdio.h>
#include "mainController.h"
#include "tank.h"

/**
 * Purpose: gets from the user the number of times the simulation will be run
 * Pre-Condition: Nothing
 * Post-Condition: Nothing
 */
void getNumOfCycles();

/**
 * Purpose: gets from the user the Min and Max values of the temperature sensors
 * and sets them
 * Pre-Condition: Nothing
 * Post-Condition: Nothing
 */
int *setMinMaxTemperature();

/**
 * Purpose: gets from the user the heights of the different water level sensors and
 * sets them
 * Pre-Condition: Nothing
 * Post-Condition: Nothing
 */
void getWaterLevelSensors();

/**
 * *****************************************************************************************************
 * ************* Everything from now on deals with displaying information back to the user *************
 */

/**
 * Hardcoding the values of the simulated tank, only used by controllers
*/
void initializeValuesTank();

//Here remember to initialize the Water Level sensors
void initializeEverything();


void startSimulation();
/**
 * Purpose: Simply prints what cycle the simulation is in
 */
void printCycleNum(int numOfCycles, int currentCycle);

/**
 * Purpose: Prints the status of the tank at the current cycle
 */
void printTankStatus(int waterLevel, int pressure, int temperature);

/**
 * Data: Somehow needs to get the status of all Physical objects
 * Purpose: Prints the status of the Physical Objects at the current cycle
 */
void printPhysicalStatus();
