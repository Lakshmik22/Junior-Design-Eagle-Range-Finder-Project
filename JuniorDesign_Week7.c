#include "msp430.h"
#include "stdio.h"
#include "Junior_Design.h"

#define DELAYT_500ms 5000
#define DELAYT_100ms 1000

// Global variables
static unsigned long int d1;
int d_1, d_10;
static unsigned int ADC_Result;
volatile unsigned int Duty;
char Data[] = "Junior Design TI ";
char Space[] = " ";
char Percentage[] = "%";
char Data2[5];
char Data3[32];

void main(void)
{
    volatile unsigned int i = 0;

    // Initialize hardware and LCD
    Init_HW();
    LCD_Initialize();

    while (1)
    {
        // Blink LED on P1.0
        P1OUT ^= BIT0;
        Delay_Timer(DELAYT_500ms);

        // Display static message
        LCD_CLRscreen();
        LCD_String(Data);
        Delay_Timer(DELAYT_500ms);

        // Ultrasonic sensor distance display
        Ultrasonic_Trigger();
        Delay_Timer(DELAYT_100ms);
        d1 = Ultrasonic_Echo_Read();
        LCD_Cursor_Postion(0x40);
        LCD_Cursor_On_No_Blink();

        d_1 = (int)((float)d1 * 0.066929);
        d_10 = (int)((float)d1 * 0.66929) - d_1 * 10;
        sprintf(Data3, "%dmm %d.%din", (int)((float)d1 * 3.4 / 2.0), d_1, d_10);
        LCD_String(Data3);
        Delay_Timer(DELAYT_500ms);

        // Potentiometer duty cycle brightness display
        ADC_Result = ADC_Read();
        Duty = (int)((float)ADC_Result / 10.23);
        Delay_Timer(DELAYT_500ms);

        sprintf(Data2, "%d", Duty);
        LCD_String(Space);
        LCD_String(Data2);
        LCD_String(Percentage);
        Delay_Timer(DELAYT_500ms);
    }
}
