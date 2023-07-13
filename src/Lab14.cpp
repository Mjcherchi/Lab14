/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/michaeljosephcherchi/Desktop/labs/Lab14/src/Lab14.ino"
void setup();
void loop();
void COUNTERisr();
void oNOFFisr();
#line 1 "/Users/michaeljosephcherchi/Desktop/labs/Lab14/src/Lab14.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"

OledWingAdafruit display;

int counter = 0;

volatile bool INA = false;

void setup()
{
    pinMode(D6, INPUT);
    pinMode(D5, INPUT);

    display.setup();

    display.clearDisplay();

    attachInterrupt(D6, COUNTERisr, FALLING);
    attachInterrupt(D5, oNOFFisr, FALLING);
}

void loop()
{
    display.loop();
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(counter);
    display.display();

    if (digitalRead(D5) && counter == 0)
    {
        interrupts();
    }

    if (INA = false)
    {
        display.loop();
        display.clearDisplay();
        display.setTextSize(3);
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println("Interrupts OFF");
        display.display();
    }
}

void COUNTERisr()
{
    counter++;
    interrupts();
}

void oNOFFisr()
{
    INA = false;
    counter = 0;
    noInterrupts();
    display.loop();
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Interrupts OFF");
    display.display();
}
