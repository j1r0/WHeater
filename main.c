#include "simulationUI.h"
#include "tank.h"
#include "physicalController.h"
#include "sensorController.h"
#include "mainController.h"

#include <stdio.h>


int main()
{
    Tank tankTest;
    tankTest.pressure = 4;
    Sensor press;
    readPressure(&press, &tankTest);
    int test = press.data;
    printf("the value of the pressure is %d\n", test);
    printf("This works :3\n");
    return 0;
}