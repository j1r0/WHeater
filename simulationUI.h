#include <stdio.h>
/**
 * Here we do the initalization of how many times the simulation will run,
 * the height of the Water level sensors, and min/max value of the temperature sensors
 */

// NEEDS TO CONNECT TO THE CONTROLLERS
typedef struct {
    float maxTemperature;
    float minTemperature;
    int criticalPressure;
    int minPressure;
    int maxPressure;
} minMaxValues;


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
void setMinMaxTemperature(minMaxValues minMax);

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
