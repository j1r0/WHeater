#include <vxWorks.h> /* Always include this as the first thing in every program */
#include <time.h> /* we use clock_gettime */
#include <taskLib.h> /* we use tasks */
#include <sysLib.h> /* we use sysClk... */
#include <semLib.h> /* we use semaphores */
#include <logLib.h> /* we use logMsg rather than printf */
#include "sensors.h"

 
int readTemperature(struct temperatureSensor temperature){
	 temperature.data = 1;
	 return temperature.data;
 }
int readPressure(struct pressureSensor pressure){
	 pressure.data = 1;
	 return pressure.data;
}
int readWaterLevel(struct waterLevelSensor waterLevel){
	
	 waterLevel.data = 1;
	 return waterLevel.data;
}
  
  int main(){
  	struct temperatureSensor tempSensor;
  	tempSensor.data =0;
  	struct pressureSensor pressSensor;
  	pressSensor.data =1;
  	struct waterLevelSensor wLevelSensor;
  	wLevelSensor.data =0;
  	return pressSensor.data;
  }

