#include <stdint.h>
#ifndef mpu_i2c_h
#define mpu_i2c_h
#define ACCEL_XOUT_H   0x3B
#define ACCEL_XOUT_L   0x3C
#define ACCEL_YOUT_H   0x3D
#define ACCEL_YOUT_L   0x3E
#define ACCEL_ZOUT_H   0x3F
#define ACCEL_ZOUT_L   0x40
#define TEMP_OUT_H     0x41
#define TEMP_OUT_L     0x42
#define GYRO_XOUT_H    0x43
#define GYRO_XOUT_L    0x44
#define GYRO_YOUT_H    0x45
#define GYRO_YOUT_L    0x46
#define GYRO_ZOUT_H    0x47
#define GYRO_ZOUT_L    0x48


#define ADDR_MPU6050     0x68
#define WAKE_UP_REGISTER 0x6b
#define WAKE_UP_DATA 	   0x01
#define I2C_TIMEOUT   	 1000

const bool  debug  = true ;

class MPU_I2C
{
  private:

    uint8_t registerAddress;
    uint8_t *data ;
    bool sendStop;
    uint8_t Length;
    uint8_t nbytes;

  public:

    void setupMpu(int8_t Delay );
    int16_t i2cRead(uint8_t registerAddress, int8_t nbytes, int32_t timeOut);
    uint8_t i2cWrite(uint8_t registerAddress, uint8_t data, bool sendStop);
    uint8_t i2cWrite(uint8_t registerAddress, uint8_t data, uint8_t Length, bool sendStop);
    int16_t getAcceX  ();
    int16_t getAcceY  ();
    int16_t getAcceZ  ();
    int16_t getGyroX ();
    int16_t getGyroY ();
    int16_t getGyroZ ();
    int16_t getTemp  ();
    void Serial_println( char *payload );
    void Serial_print ( char *payload );



};
#endif
