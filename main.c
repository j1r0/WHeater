 #include "simulationUI.h"
// #include "tank.h"
// #include "physicalController.h"
// #include "sensorController.h"
// #include "mainController.h"
#include <stdio.h>



int main()
{

    printf("hello\n");

    getNumOfCycles();
    setMinMaxTemperature();
    getWaterLevelSensors();
    initializeEverything();
    startSimulation();
    return 0;
}