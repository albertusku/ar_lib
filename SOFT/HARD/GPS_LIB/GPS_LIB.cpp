#include <TinyGPS.h>
#include <SoftwareSerial.h>

TinyGPS gps;
SoftwareSerial ss(32,33);


void ssbegin()
{
    ss.begin(9600);
}

void get_data_GPS(float & lat,float &lon,bool &flag)
{
    long unsigned int age;
    const long r=6370;
    bool data=false;
    for(int i=millis();millis()-i<1000;)
    {
        while(ss.available())
        {
        char c=ss.read();
        if(gps.encode(c))  data=true;
        }
    }
    if(data)
    {
        gps.f_get_position(&lat,&lon,&age);
        Serial.print("LAT:");
        Serial.println(lat);
        flag=true;
    }
    else flag=false;
}