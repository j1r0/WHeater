 #include "simulationUI.h"
#include "tank.h" 
// #include "physicalController.h"
// #include "sensorController.h"
// #include "mainController.h"
#include <stdio.h>



int main()
{

    printf("hello\n");
    Tank tankTest;
    // tankTest.pressure = 4;
    // Sensor press;
    // readPressure(&press, &tankTest);
    // int test = press.data;
    // printf("the value of the pressure is %d\n", test);
    // printf("This works :3\n");

    // getNumOfCycles();
    int* minMaxTemp = setMinMaxTemperature();

    printf("Max temp: %d\n, Min temp: %d", minMaxTemp[0], minMaxTemp[1]);
    updatePressure(&tankTest, 0, 100, 100);
    // int test = tankTest.pressure;
    // printf("the value of the pressure is %d\n", test);
    // getWaterLevelSensors();
    // initializeSensors(&sp,waterSensorsHeights[0], waterSensorsHeights[1], waterSensorsHeights[2],
    // waterSensorsHeights[3]);
    return 0;
}