#include <Arduino.h>
#include <SoftwareSerial.h>
#include "SERIAL_LIB.h"
//No probado

void setup_serial(bool estandar,int bau, int rx, int tx)
{
    Serial.begin(bau);
    if (!estandar)
    {
        SoftwareSerial SSerial(rx,tx);
        SSerial(bau);
    }
}

void envia_datos(bool estandar,int data)
{
    if (!estandar)
    {
         SSerial.write((byte*)&data,sizeof(data));
        delay(100);
    }
   
}

void recibe_datos(bool estandar,int& data)
{
    if (!estandar)
    {
        if(SSerial.available()>=sizeof(int))
        {
            SSerial.readBytes((byte*)&data,sizeof(data));
        }
        delay(200);
    }
    return data;
}