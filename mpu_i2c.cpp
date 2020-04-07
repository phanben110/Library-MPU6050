/*
   Phan Ben 
   email phanben110@gmail.com
   face: https://www.facebook.com/ben.phan.5011
 */
#include "mpu_i2c.h"
#include <Arduino.h>
#include <Wire.h>

void MPU_I2C::setupMpu(int8_t Delay )
{
  Wire.begin();
  delay(Delay);
 i2cWrite(0x1b, 0b11000, false); 
  i2cWrite(0x6b, 0x01, false);


//
//  Wire.beginTransmission(ADDR_MPU6050 );
//  Wire.write(0x1b);
//  Wire.write(0b11000);
//  Wire.endTransmission();
//
//
//  Wire.beginTransmission(ADDR_MPU6050 );
//  Wire.write(0x6b);
//  Wire.write(0x01);
//  Wire.endTransmission();
}


uint8_t MPU_I2C::i2cWrite( uint8_t registerAddress, uint8_t data , bool sendStop)
{
	return i2cRead(registerAddress, 1, sendStop );
}

uint8_t MPU_I2C::i2cWrite( uint8_t registerAddress , uint8_t data, uint8_t Length , bool sendStop)
{
	 Wire.beginTransmission(ADDR_MPU6050);
  Wire.write(registerAddress);
  Wire.write(data);
  uint8_t rcode = Wire.endTransmission(sendStop); // Returns 0 on success
  if (rcode) {
    Serial_print("i2cWrite failed: ");
    Serial_println(rcode);
  }
  return rcode; // See: http://arduino.cc/en/Reference/WireEndTransmission
} 


int16_t MPU_I2C::i2cRead(uint8_t registerAddress, int8_t nbytes, int32_t timeOut)
{
  Wire.beginTransmission( ADDR_MPU6050 );
  Wire.write(registerAddress);
  int8_t rcode = Wire.endTransmission(false);
  if (rcode)
  {
    Serial_print("i2cread failed: ");
    Serial_println( rcode );
    return rcode;
  }
  Wire.requestFrom( ADDR_MPU6050,2);
  return (Wire.read() << 8) | Wire.read();
  unsigned long timeOUT = micros() ;  
  while((micros()- timeOUT) < I2C_TIMEOUT  && !Wire.available() );
  if ( Wire.available())
  {
    Serial_println("sucess");
    return (Wire.read() << 8 ) | Wire.read();
  }
  else 
  {
    Serial_println ("some thing wrong");
    return 0 ;
  }
 return (Wire.read() << 8) | Wire.read();
}


int16_t MPU_I2C::getAcceX()
{
  return i2cRead(ACCEL_XOUT_H, 2, I2C_TIMEOUT);
}

int16_t MPU_I2C::getAcceY()
{
  return i2cRead(ACCEL_YOUT_H, 2, I2C_TIMEOUT);
}

int16_t MPU_I2C::getAcceZ()
{
  return i2cRead(ACCEL_ZOUT_H, 2, I2C_TIMEOUT);
}


int16_t MPU_I2C::getGyroX()
{
  return i2cRead(GYRO_XOUT_H, 2, I2C_TIMEOUT);
}

int16_t MPU_I2C::getGyroY()
{
  return i2cRead(GYRO_XOUT_H, 2, I2C_TIMEOUT);
}

int16_t MPU_I2C::getGyroZ()
{
  return i2cRead(GYRO_XOUT_H, 2, I2C_TIMEOUT);
}


int16_t MPU_I2C::getTemp()
{
  return i2cRead(TEMP_OUT_H, 2, I2C_TIMEOUT);
}


void MPU_I2C::Serial_print(  char *payload )
{
	if ( debug )
	{
		Serial.print( payload );
	}
}

void MPU_I2C::Serial_println( char *payload)
{
	if (debug)
	{
		Serial.println( payload);
	}
}
