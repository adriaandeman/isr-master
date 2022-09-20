#ifndef ISR_H
#define ISR_H

#include <Arduino.h>

class Isr {
private:
  byte pin;
  static volatile bool debounce_time;

public:
  Isr(byte pin,int pin_mode,int debounce_time);
  void resetCounter();

  static volatile bool state;
  static volatile int counter;

protected:
  static void handler();

};



#endif
