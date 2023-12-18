// Real Time Clock

#include <DS3231.h>

// Instantiate a real-time clock object of class DS3231
DS3231 realTimeClock;
// Instantiate a date object of class RTCDateTime
RTCDateTime dt;
// Create a character buffer to store the formatted date string
char dateBuffer[124];

void setup()
{
  // Open a serial connection with Baud rate of 9600
  Serial.begin(9600);
  Serial.println("Initializing RTC module...");
  // Initialize the DS3231 RTC module
  realTimeClock.begin();
  // Send the compilation time of the sketch to the Arduino board
  realTimeClock.setDateTime(__DATE__, __TIME__);
}

void loop()
{
  // Get the current date-time
  dt = realTimeClock.getDateTime();
  // Print the formatted date-time string
  sprintf(dateBuffer, "The current date/time is: %d-%d-%d %d:%d:%d\n", dt.day, dt.month, dt.year, dt.hour, dt.minute, dt.second);
  Serial.print(dateBuffer);
  // Add a one second delay before updating the serial monitor
  delay(1000);
}
