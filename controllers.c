#define VOLUME 50
#define MAX_OP_PRESSURE_PSI 30
#define MIN_OP_PRESSURE_PSI 20
#define CRIT_PRESSURE_PSI 50
#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE 10

#include "physical.h"

struct controller {
	int temperatureReading;
	int pressureReading;
	int waterLevelReading;
	int waterHeight;
};

struct controller ctrl;

int setMaxWaterLevelHeight(){
	ctrl.waterHeight = 200;
	return ctrl.waterHeight;
}

int waterLevelController(){
	
	
	if( ctrl.waterHeight < ctrl.waterLevelReading){
		return 0;
	}
	
}
int pressureController(){
	
	if( ctrl.pressureReading > MAX_OP_PRESSURE_PSI){
		return 0;
	}
	
	if( ctrl.pressureReading < MIN_OP_PRESSURE_PSI){
		return 0;
	}
	
	if( ctrl.pressureReading > CRIT_PRESSURE_PSI){
		return 0;
	}
	
	return 1;
}

int temperatureController(){
	
	if( ctrl.temperatureReading > MAX_TEMPERATURE){
		return 0;
	}
	
	if( ctrl.temperatureReading < MIN_TEMPERATURE){
		return 0;
	}
	
	return 1;
}
