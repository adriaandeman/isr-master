#ifndef ISR_H
#define ISR_H

#include <Arduino.h>

class Isr {
  private:
    byte pin;

  public:
    Isr(byte pin,int pin_mode,int debounce_time);
    static volatile bool state;
    static volatile bool debounce_time;

  protected:
    static void handler();

};



#endif
