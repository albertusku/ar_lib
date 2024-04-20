#ifndef D_motor_h
#define D_motor_h
#include <Arduino.h>

void setup_motors(int,int);
void adelante();
void atras();
void giro_der();
void giro_izq();
void freno();
void setspeed(double,double);

#endif