#define NANOS_IN_SEC 1000000000
#define NANOS_PER_MILLI 1000000
#define TICK sysClkRateGet()/60

struct temperatureSensor {
	int data;
};
struct pressureSensor {
	int data;
};
 
struct waterLevelSensor {
	 int data;
 };
 
 
int readTemperature(struct temperatureSensor temperature);
int readPressure(struct pressureSensor pressure);
int readWaterLevel(struct waterLevelSensor waterLevel);
