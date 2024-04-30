#include "simulationUI.h"

/**
 * This array contains the heights of the 4 water level sensors
 */
float waterSensorsHeights[4];

/**
 * This array contains the Min and Max of the temperature sensor
 */
float temperatureSensorMinMax[2];

/**
 * This is for the amount of cycles the simulation will be run for
 */
int numOfCycles;
int currentCycle;

void getNumOfCycles()
{
    printf("Select the number of cycles to run the simulation for: \n");
    scanf("%d", &numOfCycles );
    printf("Number of cycles: %d\n", numOfCycles);
    
}

void setMinMaxTemperature(minMaxValues minMax)
{
    float userMaxTemp, userMinTemp;
    printf("Input Maximum temperature in Celsius: \n");
    scanf("%f", &userMaxTemp );

    minMax.maxTemperature = userMaxTemp;

    printf("Max temp: %f\n",minMax.maxTemperature);

    printf("Input Minimum temperature in Celsius: \n");
    scanf("%f", &userMinTemp );

    minMax.minTemperature = userMinTemp;

    printf("Max temp: %f\n",minMax.minTemperature);

}

void getWaterLevelSensors()
{   
    printf("The maximum height of the tank is 20m\n");
    for(int i = 0; i < 4; i++)
    {
        float height;
        printf("Please input height of Water Level Sensor #%d\n", i+1);
        scanf("%f",&height);
        waterSensorsHeights[i] = height;
        printf("Height of WLS #%d is %f\n", i+1, waterSensorsHeights[i]);
    }
}

// void initializeEverything()
// {
//     initializeSensors(*sp,waterSensorsHeights[0], waterSensorsHeights[1], waterSensorsHeights[2], 
//     waterSensorsHeights[3]);
    
// }

