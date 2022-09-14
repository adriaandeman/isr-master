#include "isr.h"

Isr::Isr(byte pin, int pin_mode,int debounce_time) {
  this->pin = pin;
  this->debounce_time = debounce_time;
  pinMode(pin,pin_mode);
  attachInterrupt(pin, handler, FALLING);
}

void Isr::handler() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce_time) {
    state = !state;
  }
  last_interrupt_time = interrupt_time;
}

volatile bool Isr::state = true;
volatile bool Isr::debounce_time;
