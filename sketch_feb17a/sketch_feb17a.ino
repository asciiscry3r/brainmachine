#include <avr/pgmspace.h>  // for arrays - PROGMEM
//#include <Tone.h>          // Include the arduino tone library
#include <avr/sleep.h>  // A library to control the sleep mode
#include <avr/power.h>  // A library to control power

#define SIGNAL0Low 2    // SIGNAL only Hight/Low PWM

#define SIGNAL1Low 8    // SIGNAL only Hight/Low PWM
#define SIGNAL2Low 11   // SIGNAL
#define SIGNAL3Low 4    // SIGNAL only Hight/Low PWM
#define SIGNAL4Low 3    // SIGNAL
#define SIGNAL5Low 7    // SIGNAL only Hight/Low PWM
#define SIGNAL6Low 1    // SIGNAL only Hight/Low PWM
#define SIGNAL7Low 12   // SIGNAL only Hight/Low PWM
#define SIGNAL8Low 13   // SIGNAL only Hight/Low PWM
#define SIGNAL9Low 5    // SIGNAL
#define SIGNAL10Low 6   // SIGNAL
#define SIGNAL11Low 9   // SIGNAL
#define SIGNAL12Low 10  // SIGNAL

long randNumber;

void setup() {

  pinMode(SIGNAL1Low, OUTPUT);
  pinMode(SIGNAL2Low, OUTPUT);
  pinMode(SIGNAL3Low, OUTPUT);
  pinMode(SIGNAL1Low, OUTPUT);
  pinMode(SIGNAL5Low, OUTPUT);
  pinMode(SIGNAL6Low, OUTPUT);
  pinMode(SIGNAL7Low, OUTPUT);
  pinMode(SIGNAL8Low, OUTPUT);
  pinMode(SIGNAL9Low, OUTPUT);
  pinMode(SIGNAL10Low, OUTPUT);
  pinMode(SIGNAL11Low, OUTPUT);
  pinMode(SIGNAL12Low, OUTPUT);

  randomSeed(analogRead(A0) + analogRead(A1));
}


void loop() {
  analogReference(EXTERNAL);
  runrandomsignals();

  delay_one_tenth_ms(10);
}


void runrandomsignals() {
  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL1Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL2Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL3Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL4Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL5Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL6Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL7Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL8Low, randNumber);
}


void delay_one_tenth_ms(unsigned long int ms) {
  unsigned long int timer;
  const unsigned long int DelayCount = 196;  // Default: 87 - this value was determined by trial and error

  while (ms != 0) {
    // Toggling PD0 is done here to force the compiler to do this loop, rather than optimize it away
    for (timer = 0; timer <= DelayCount; timer++) { PIND |= 0b0000001; };
    ms--;
  }
}
