typedef struct minMax{
    float maxTemperature;
    float minTemperature;
    int criticalPressure;
    int minPressure;
    int maxPressure;
} minMaxValues;

/**
 * Forward Declaration - Sensor Values is defined in sensorController.h
*/
struct SensorValues;

/**
 * Forward Declaration - Both defined in physical.h
*/
struct Heater;
struct Valve;

/**
 * Purpose: initialize water level sensor's heights
 * WE NEED TO KNOW HOW TALL TANK WILL BE
*/
void initializeSensorsMain(float height1, float height2, float height3, float height4);

/**
 * Purpose: Simply to set the min and maximum values of the temperature sensors
*/
void initializePhysicalMain(float maxTemperature, float minTemperature);

/**
 * Purpose: Used as the temperature controller. Simply decides what to do with the Heater
*/
void temperatureController(Heater *this, minMaxValues minMax);

/**
 * Data: sensorValuesPackage.pressure - The current reading of the temperature
 * Purpose: Used as the pressure controller. Simply decides what to do with the Outlet valve
 * Post-Condition: The status of the outlet valve changes/stays the same
*/
void pressureController();

void waterLevelController();