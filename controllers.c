#define VOLUME 50
#define MAX_OP_PRESSURE_PSI 30
#define MIN_OP_PRESSURE_PSI 20
#define CRIT_PRESSURE_PSI 50
#define MAX_TEMPERATURE 100
#define MAX_TEMPERATURE 10

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
