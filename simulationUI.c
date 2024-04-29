#include "simulationUI.h"
#include <stdio.h>

void getNumOfCycles()
{
    printf("Select the number of cycles to run the simulation for: ");
    scanf("%d \n", &numOfCycles );
    printf("Number of cycles: %d\n", numOfCycles);
    
}

int main()
{
    getNumOfCycles();
}