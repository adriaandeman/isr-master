#include "isr.h"

Isr::Isr(byte pin, int pin_mode,int debounce_time) {
  this->pin = pin;
  this->debounce_time = debounce_time;
  pinMode(pin,pin_mode);
  attachInterrupt(pin, handler, RISING);
}

void Isr::handler() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce_time) {
    state = !state;
    counter++;
  }
  last_interrupt_time = interrupt_time;
}

void Isr::resetCounter(){
  noInterrupts();
  counter=0;
  interrupts();
}

volatile bool Isr::state = true;
volatile bool Isr::debounce_time;
volatile int Isr::counter = 0;
