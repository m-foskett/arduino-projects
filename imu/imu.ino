// IMU

#include<Wire.h>

// I2C address of the MPU-6050
const int MPU_addr=0x68;
// Variable Definitions for the IMU measurements
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
char buffer[128];

void setup() {
  Wire.begin();
  // Begin connection with the I2C address of the IMU
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // Set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  // Begin serial connection with Baud rate of 9600
  Serial.begin(9600);
}
void loop() {
  // Begin connection with the I2C address of the IMU
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // Starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);  // Request a total of 14 registers
  AcX = Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY = Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp = Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX = Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY = Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ = Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  sprintf(buffer, "Accelerometer Readings\nAcX: %d AcY: %d AcZ: %d\nTemp: %d\nGyroscope Readings:\nGyX: %d GyY: %d GyZ: %d\n", AcX, AcY, AcZ, Tmp/340.00+36.53, GyX, GyY, GyZ);
  Serial.print(buffer);
  // Serial.print("AcX = "); Serial.print(AcX);
  // Serial.print(" | AcY = "); Serial.println(AcY);
  // Serial.print(" | AcZ = "); Serial.print(AcZ);
  // Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //From the datasheet of MPU6050, we can know the temperature formula
  // Serial.print(" | GyX = "); Serial.print(GyX);
  // Serial.print(" | GyY = "); Serial.println(GyY);
  // Serial.print(" | GyZ = "); Serial.println(GyZ);
  delay(1000);
}
