// DHT11 - Temperature and Humidity Sensor

#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

// Variable Definitions
static const int DHT_SENSOR_PIN = 2;
// Instantiate DHT11 object
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup( )
{
  // Initialize the serial port
  Serial.begin( 9600);
}

// Function: measure_environment
//  Parameters: 
//    float pointer - temperature
//    float pointer - humidity
//  Returns:
//    boolean - true if a measurement is available
//  Operation:
//    - Poll for a measurement whilst keeping the state machine running
static bool measure_environment( float *temperature, float *humidity ) {
  // Timestamp of the measurement
  static unsigned long measurement_timestamp = millis( );

  // Measure periodically every four seconds
  if( millis( ) - measurement_timestamp > 3000ul ) {
    if( dht_sensor.measure( temperature, humidity ) == true ) {
      // Update the measurement timestamp
      measurement_timestamp = millis( );
      // Return true that a measurement was acquired
      return( true );
    }
  }
  // Otherwise return false if no measurement was found
  return( false );
}

void loop( )
{
  // Temperature and Humidity variable definitions
  float temperature;
  float humidity;
  // Pass by reference of the address of the temperature and humidity floats to update them
  // with the new measurement
  if( measure_environment( &temperature, &humidity ) == true ) {
    // Print the acquired values to the serial monitor
    Serial.print( "Temperature = " );
    Serial.print( temperature, 1 );
    Serial.print( " degrees Celsius, Humidity = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
  }
}
