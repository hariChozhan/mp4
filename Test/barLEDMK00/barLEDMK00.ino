#define ARDUINO_MAIN
#include "wiring_private.h"
#include "pins_arduino.h"

//Pins Definition
int barLed[] = {29, 30, 31, 32, 33, 34, 35, 36, 37, 38};
int discoLed = 0;

void pinDef(uint8_t pin, uint8_t mode)
{
  uint8_t bit = digitalPinToBitMask(pin);
  uint8_t port = digitalPinToPort(pin);
  volatile uint8_t *reg, *out;
  if (port == NOT_A_PIN) return;
  reg = portModeRegister(port);
  out = portOutputRegister(port);
  if (mode == INPUT) {
    uint8_t oldSREG = SREG;
    cli();
    *reg &= ~bit;
    *out &= ~bit;
    SREG = oldSREG;
  } else if (mode == INPUT_PULLUP) {
    uint8_t oldSREG = SREG;
    cli();
    *reg &= ~bit;
    *out |= bit;
    SREG = oldSREG;
  } else {
    uint8_t oldSREG = SREG;
    cli();
    *reg |= bit;
    SREG = oldSREG;
  }
}

static void turnOffPWM(uint8_t timer)
{
  switch (timer)
  {
#if defined(TCCR1A) && defined(COM1A1)
    case TIMER1A:   cbi(TCCR1A, COM1A1);    break;
#endif
#if defined(TCCR1A) && defined(COM1B1)
    case TIMER1B:   cbi(TCCR1A, COM1B1);    break;
#endif
#if defined(TCCR1A) && defined(COM1C1)
    case TIMER1C:   cbi(TCCR1A, COM1C1);    break;
#endif

#if defined(TCCR2) && defined(COM21)
    case  TIMER2:   cbi(TCCR2, COM21);      break;
#endif

#if defined(TCCR0A) && defined(COM0A1)
    case  TIMER0A:  cbi(TCCR0A, COM0A1);    break;
#endif

#if defined(TCCR0A) && defined(COM0B1)
    case  TIMER0B:  cbi(TCCR0A, COM0B1);    break;
#endif
#if defined(TCCR2A) && defined(COM2A1)
    case  TIMER2A:  cbi(TCCR2A, COM2A1);    break;
#endif
#if defined(TCCR2A) && defined(COM2B1)
    case  TIMER2B:  cbi(TCCR2A, COM2B1);    break;
#endif

#if defined(TCCR3A) && defined(COM3A1)
    case  TIMER3A:  cbi(TCCR3A, COM3A1);    break;
#endif
#if defined(TCCR3A) && defined(COM3B1)
    case  TIMER3B:  cbi(TCCR3A, COM3B1);    break;
#endif
#if defined(TCCR3A) && defined(COM3C1)
    case  TIMER3C:  cbi(TCCR3A, COM3C1);    break;
#endif

#if defined(TCCR4A) && defined(COM4A1)
    case  TIMER4A:  cbi(TCCR4A, COM4A1);    break;
#endif
#if defined(TCCR4A) && defined(COM4B1)
    case  TIMER4B:  cbi(TCCR4A, COM4B1);    break;
#endif
#if defined(TCCR4A) && defined(COM4C1)
    case  TIMER4C:  cbi(TCCR4A, COM4C1);    break;
#endif
#if defined(TCCR4C) && defined(COM4D1)
    case TIMER4D: cbi(TCCR4C, COM4D1);  break;
#endif

#if defined(TCCR5A)
    case  TIMER5A:  cbi(TCCR5A, COM5A1);    break;
    case  TIMER5B:  cbi(TCCR5A, COM5B1);    break;
    case  TIMER5C:  cbi(TCCR5A, COM5C1);    break;
#endif
  }
}

void digitalwrite(uint8_t pin, uint8_t val)
{
  uint8_t timer = digitalPinToTimer(pin);
  uint8_t bit = digitalPinToBitMask(pin);
  uint8_t port = digitalPinToPort(pin);
  volatile uint8_t *out;
  if (port == NOT_A_PIN) return;
  if (timer != NOT_ON_TIMER) turnOffPWM(timer);
  out = portOutputRegister(port);
  uint8_t oldSREG = SREG;
  cli();
  if (val == LOW) {
    *out &= ~bit;
  } else {
    *out |= bit;
  }

  SREG = oldSREG;
}

int digitalread(uint8_t pin)
{
  uint8_t timer = digitalPinToTimer(pin);
  uint8_t bit = digitalPinToBitMask(pin);
  uint8_t port = digitalPinToPort(pin);
  if (port == NOT_A_PIN) return LOW;
  if (timer != NOT_ON_TIMER) turnOffPWM(timer);
  if (*portInputRegister(port) & bit) return HIGH;
  return LOW;
}

void barLedDisplay() {
  for (int ledArray = 0; ledArray < 10; ledArray++) {
    digitalwrite(barLed[ledArray], LOW);
  }
  discoLed = random(10);
  for (int ledArray = 0; ledArray < discoLed; ledArray++) {
    digitalwrite(barLed[ledArray], HIGH);
  }
  for (int ledArray = 0; ledArray < 10; ledArray++) {
    digitalwrite(barLed[ledArray], LOW);
  }
}

void setup() {
  for (int ledArray = 0; ledArray < 10; ledArray++) {
    pinDef(barLed[ledArray], OUTPUT);
  }
}
void loop() {
  barLedDisplay();
}
