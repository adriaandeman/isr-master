#include <isr.h>

//create array of objects that all have their of interrupt handler that returns false if true and visa versa.

Isr isr[3] = {
  Isr(14, INPUT_PULLUP, 200), //set pin, pinmode, debounce time in Milli seconds.
  Isr(15, INPUT_PULLUP, 200),
  Isr(16, INPUT_PULLUP, 200)
};

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.print("loop -> state: ");
  Serial.print(isr[0].state);
  Serial.print(" -> count: ");
  Serial.println(isr[0].counter);
  delay(200);

  if ( isr[0].counter >3) isr[0].resetCounter();
}
