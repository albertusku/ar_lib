#include <Adafruit_GFX.h>      // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>  // libreria para controlador SSD1306
#include "OLED_LIB.h"


#define ANCHO 128
#define ALTO 64
#define OLED_RESET -1

Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // objeto oled
int oled_dir=0x3C;

void setup_oled()
{
    bool oled_status=oled.begin(SSD1306_SWITCHCAPVCC, oled_dir);
    if(!oled_status) 
    {
        Serial.println("OLED NOT FOUND");
        for(;;);
        
    }
    oled.clearDisplay();
    oled.display();

}

void print_image(int img,int x,int y)
{
    switch (img)
    {
        case 0:
        oled.drawBitmap(x, y, n0i,32,32, 1);
        oled.display();
        break;

        case 1: 
        oled.drawBitmap(x, y, n1i,32,32, 1);
        oled.display();
        break;

        case 2: 
        oled.drawBitmap(x, y, n2i,32,32, 1);
        oled.display();
        break;

        case 3: 
        oled.drawBitmap(x, y, n3i,32,32, 1);
        oled.display();
        break;

        case 4: 
        oled.drawBitmap(x, y, n4i,32,32, 1);
        oled.display();
        break;

        case 5: 
        oled.drawBitmap(x, y, n5i,32,32, 1);
        oled.display();
        break;

        case 6: 
        oled.drawBitmap(x, y, n6i,32,32, 1);
        oled.display();
        break;

        case 7: 
        oled.drawBitmap(x, y, n7i,32,32, 1);
        oled.display();
        break;

        case 8: 
        oled.drawBitmap(x, y, n8i,32,32, 1);
        oled.display();
        break;

        case 9: 
        oled.drawBitmap(x, y, n9i,32,32, 1);
        oled.display();
        break;

        case 10://Reloj
        oled.clearDisplay();
        oled.drawBitmap(35, 5, image_data_reloj,58, 64, 1);
        oled.display();
        break;

        case 11://C
        oled.drawBitmap(x,y,grados,16,16,1);
        oled.display();
        break;

        case 12://Wfi conectado????
        oled.drawBitmap(x,y,wifi_c,16,16,1);
        oled.display();
        break;

        case 13://Wifi con !
        oled.drawBitmap(x,y,wifi_nc,16,16,1);
        oled.display();
        break;

        case 14://GPS activo
        oled.drawBitmap(x,y,geo_c,16,16,1);
        oled.display();
        break;

        case 15://GPS no activo
        oled.drawBitmap(x,y,geo_nc,16,16,1);
        oled.display();
        break;

        case 16:
        oled.drawBitmap(x,y,sub_temp,16,16,1);
        oled.display();
        break;

        case 17:
        oled.drawBitmap(x,y,baj_temp,16,16,1);
        oled.display();
        break;

    }
}

void print_text(String text,int f,int c,bool color,bool clear ,int tam)
{
    if(clear) oled.clearDisplay();
    if(color)
    {
        oled.setTextColor(SSD1306_BLACK);
        oled.fillRect(f,c-1,75,9,1);
    } 
    else oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(tam);
    oled.setCursor(f,c);
    oled.print(text);
    oled.display();
}

void print_var(String text,float num,int f,int c,int dec,bool color,bool clear)
{
     if(clear) oled.clearDisplay();
    if(color)
    {
        oled.setTextColor(SSD1306_BLACK);
        oled.fillRect(f,c-1,62,9,1);
    } 
    else oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(1);
    oled.setCursor(f,c);
    oled.print(text);
    oled.print(num,dec);
    oled.display();
}

void oled_write(int n,int f,int c)
{
  oled.write(n);
}

void special_print(String text)
{
    oled.print(text);
    oled.print("");
}
void oled_sleep()
{
  oled.clearDisplay();
  oled.display();
}

void draw_line(int x0,int y0,int x1,int y1)
{
    oled.drawLine(x0,y0,x1,y1,SSD1306_WHITE);
    oled.display();
}