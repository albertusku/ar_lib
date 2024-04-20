#include <WiFi.h>  
#include <HTTPClient.h>
#include "WLAN_LIB.h"
#include <WiFiGeneric.h>
#include <esp_err.h>
#include <esp_event_loop.h>
#include <functional>
#include "WiFiType.h"
#include "IPAddress.h"
#include <wifi_provisioning/manager.h>
#include <WiFiMulti.h>
#include "VAR_GLOB.h"

int Wlan_status=WL_IDLE_STATUS;
WLAN_PROF prof_WLAN;
std::vector<std::pair<String,String>> WLAN_SSID_PASS={{"MiFibra-9805","4orwHr9A"}};


void setup_WLAN()
{
    WiFi.mode(WIFI_STA);
    init_com(WLAN_SSID_PASS);
}


void init_com(std::vector<std::pair<String,String>> conexion)
{
  
  for(const auto i:conexion)
  {
    int attempts_connect=0;
    while(Wlan_status != WL_CONNECTED && attempts_connect!=6 )
    {
        Wlan_status=WiFi.begin(i.first.c_str(),i.second.c_str());
        Serial.print("CONNECTING WLAN---->");
        Serial.print(i.first.c_str());
        Serial.print(" ,n attemps:");
        Serial.println(attempts_connect);
        ++attempts_connect;
        delay(10000);
    }
    if (attempts_connect>=10) Serial.println("WLAN NOT CONNECTED---->attemps>=10");
    if (Wlan_status==WL_CONNECTED)
    {
      Serial.print("WLAN CONNECTED----->");
      Serial.println(i.first.c_str());
      update_WLAN_PROF();
    }
  }
}

bool is_connected()
{
    if(WiFi.status()==WL_CONNECTED) return true;
    return false;
}

WLAN_PROF get_WPROF()
{
  return prof_WLAN;
}


bool WLAN_PROF::get_connection_status() {return connection_status;}
String WLAN_PROF::get_ip(){return ip;}
String WLAN_PROF::get_ssid(){return ssid;}
String WLAN_PROF::get_mac(){return mac;}
void WLAN_PROF::set_connection_status()
{
  if (WiFi.status()==WL_CONNECTED)connection_status=true;
  else connection_status=false;
}
void WLAN_PROF::set_ip(){ip=String(WiFi.localIP());}
void WLAN_PROF::set_ssid(){ssid=String(WiFi.SSID());}
void WLAN_PROF::set_mac(){mac=String(WiFi.macAddress());}

void update_WLAN_PROF()
{
  prof_WLAN.set_connection_status();
  prof_WLAN.set_ip();
  prof_WLAN.set_mac();
  prof_WLAN.set_ssid();
}
void disconnect_WLAN()
{
  WiFi.disconnect();
  Wlan_status=WL_DISCONNECTED;
  Serial.println("WLAN NOT ACTIVE");
  update_WLAN_PROF();
}





