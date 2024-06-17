#include <Arduino.h>

#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"

void setup()
{
    Config_Init();
    LCD_Init();

    LCD_SetBacklight(100);
}


void loop()
{
#if 1
    Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 90, WHITE);
    Paint_Clear(WHITE);

    Paint_DrawString_EN(30, 10, "Hallo!", &Font24, YELLOW, RED);  
    Paint_DrawString_EN(30, 34, "Dies Test ist!", &Font24, BLUE, CYAN);
    

    delay(3000);
#endif
}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/