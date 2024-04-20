#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>
#include "BOTTELE_LIB.h"
#include <vector>

#define BOT_TOKEN "6546943490:AAFMCrkv9-P8tusV1EZvVxLKZv4Q_AtrOuk"
#define CHAT_ID "342783333"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
String idchat="";

void send_messages(String msg)
{
    bot.sendMessage("342783333",msg);
}

void setup_bottele()
{
    secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
    send_messages("BOT INICIADO");
    Serial.println("BOT INICIADO");
}

int receive_messages(int new_msg)
{
    
    for(size_t i=0;i<new_msg;++i)
    {
        idchat=String(bot.messages[i].chat_id);
        if (idchat!=CHAT_ID)
        {
            bot.sendMessage(idchat,"Usuario no permitido");
            continue;
        }
       String msg=String(bot.messages[i].text);
       Serial.print("BOT send-->");
       Serial.println(msg);
       if(msg[0]=='/') 
       {
        msg.remove(0,1);
        //100--->WLAN
        //200--->BME
        //300--->GPS
        if (msg=="WPROF") return 100;
        if (msg=="WOFF") return 101;
        if (msg=="BME") return 200;
        if(msg=="GPS") return 300;
        if(msg=="FLAG_GPS")return 301;
       }
    }
    return 55;
    
}

int listen_bot(bool Wifi_connection)
{
    if (Wifi_connection)
    {
        int cant_mensajes=bot.getUpdates(bot.last_message_received+1);//Recibo mensajes
        return receive_messages(cant_mensajes);
    }
    else 
    {
        return -1;
    }

}