#include <Arduino.h>
#include <AFMotor.h>

AF_DCMotor m3(3);
AF_DCMotor m4(4);


void setup_motors(int vel_m3,int vel_m4)
{
  m3.setSpeed(vel_m3);
  m4.setSpeed(vel_m4); 
}

void adelante()
{
    m3.run(FORWARD);
    m4.run(FORWARD);
}

void atras()
{
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void giro_izq()
{
  m3.run(FORWARD);
  m4.run(BACKWARD);
}

void giro_der()
{
  m3.run(BACKWARD);
  m4.run(FORWARD);
}

void freno()
{
  m3.run(RELEASE);
  m4.run(RELEASE);
}

void setspeed(double speed_m3,double speed_m4)
{
  m3.setSpeed(speed_m3);
  m4.setSpeed(speed_m4);
}
