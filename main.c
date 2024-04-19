#include "sensorController.h"
#include "physicalController.h"
#include "tankSimulator.h"
#include <stdio.h>

// this is just for testing. We need to run everything as different tasks
int x = 10;
int *pointer;
Heater p;


int main()
{
    p.isOn = true;
    physicalPackage p1;
    p1.heater = p;
    
    if (p1.heater.isOn)
    {
        printf("This is true!\n");
    } else{
        printf("False :c\n");
    }
    return 0;
}