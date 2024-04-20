#include <Adafruit_BME280.h>
#include "BME_LIB.h"

Adafruit_BME280 bme;
int bme_dir=0x76;

void setup_bme()
{
    bool bme_status=bme.begin(bme_dir);
    if(!bme_status)
    {
        Serial.println("BME NO ENCONTRADO");
    }
}

void get_bme_data(int &temp,int &hum,int &alt)
{
    temp=bme.readTemperature()-0.8;
    hum=bme.readHumidity();
    alt=bme.readAltitude(presionniveldelmar);
}