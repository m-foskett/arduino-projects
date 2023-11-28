// Define the pins
#define BLUE 3
#define GREEN 5
#define RED 6

// Setup Function
void setup()
{
  // Set the three pins to output
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  // Start with an initial colour of red
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

// Define the variables with initial values
int redValue = 255;
int greenValue = 0;
int blueValue = 0;

// Main loop
void loop()
{
#define delayTime 10 // fading time between colors

  for (int i = 0; i < 255; i += 1) // Red fades out, Green fades in fully when i=255
  {
    redValue -= 1;
    greenValue += 1;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(delayTime);
  }

  for (int i = 0; i < 255; i += 1) // Green fades out, Blue fades in fully when i=255
  {
    greenValue -= 1;
    blueValue += 1;
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }

  for (int i = 0; i < 255; i += 1) // Blue fades out, Red fades in fully when i=255
  {
    blueValue -= 1;
    redValue += 1;
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(delayTime);
  }
}
