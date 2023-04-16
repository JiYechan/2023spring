#include <TM1637Display.h>


const int CLK_PIN = 9;
const int DIO_PIN = 8;

TM1637Display display(CLK_PIN, DIO_PIN); 

unsigned long startTime; 
const unsigned long timerDuration = 600000; 
bool timerExpired = false; 

void setup() {
  display.setBrightness(0x0f); 
  display.showNumberDec(600);
  delay(1000);
  startTime = millis(); 
}

void loop() {
  if (!timerExpired) { 
    unsigned long currentTime = millis(); 
    unsigned long elapsedTime = currentTime - startTime;

    int remainingTime = (timerDuration - elapsedTime) / 1000;
    int minutes = remainingTime / 60;
    int seconds = remainingTime % 60;
    display.showNumberDecEx(minutes * 100 + seconds, (0x80 >> 0) | (0x80 >> 1), true);

    if (elapsedTime >= timerDuration) { 
      timerExpired = true; 
      unsigned long delayTime = millis() - currentTime; 
      display.showNumberDec(delayTime); 
    }
  }
}
