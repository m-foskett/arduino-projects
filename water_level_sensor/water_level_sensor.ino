// Water Level Sensor

// Variable Defintions
const int analogInput = 0;
int storedValue = 0;
char dataBuffer[128];

void setup()
{
  // Open a serial connection with Baud rate of 9600
  Serial.begin(9600);
}

void loop()
{
    // Read the analog input from the water level sensor
    int measuredValue = analogRead(analogInput);

    // Print the measured water level value when the difference is larger than 10
    if( ((storedValue >= measuredValue) && ((storedValue - measuredValue) > 10)) || ((storedValue < measuredValue) && ((measuredValue - storedValue) > 10)) ) {
      // String Print Format to combine results into a formatted string
      sprintf(dataBuffer,"ADC %d level is %d\n", analogInput, measuredValue);
      // Display the formatted string
      Serial.print(dataBuffer);
      // Update the stored value with the latest measured value
      storedValue = measuredValue;
    }
}
