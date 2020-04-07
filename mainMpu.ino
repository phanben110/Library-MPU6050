/*
   Phan Ben 
   email phanben110@gmail.com
   face: https://www.facebook.com/ben.phan.5011
 */
#include "mpu_i2c.h"
#include <math.h>
MPU_I2C mpu ;
float acceX, acceY, acceZ, cal ;

void setup()
{
  Serial.begin(115200);
  mpu.setupMpu(10);
}

void loop()
{
  //Serial.println(mpu.getAcceX());
  //Serial.println(acceX);
  //  Serial.println(mpu.getAcceY());
  //  Serial.println(mpu.getAcceZ());

  //	acceX = map(mpu.getAcceX(), -16384, 16384, -90,90);
  //	acceY = map(mpu.getAcceY(), -16384, 16384, -90,90);
  //	acceZ = map(mpu.getAcceZ(),-16384, 16384, -90,90);

  acceX = map(mpu.getAcceX(), -16384, 16384, -3.14159*2, 3.14159*2);
  acceY = map(mpu.getAcceY(), -16384, 16384, -3.14159*2, 3.14159*2);
  acceZ = map(mpu.getAcceZ(), -16384, 16384, -3.14159*2, 3.14159*2);
  cal = sqrt ( ( acceX * acceX ) + ( acceY * acceY ) + (acceZ * acceZ));
  Serial.println(cal);
  delay(200);
}
