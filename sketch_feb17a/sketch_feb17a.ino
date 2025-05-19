//#include <avr/pgmspace.h>  // for arrays - PROGMEM
//#include <avr/sleep.h>     // A library to control the sleep mode
//#include <avr/power.h>     // A library to control power
//#include <Tone.h>  // Include the arduino tone library

#define SIGNAL0Low 2    // SIGNAL only Hight/Low PWM
#define SIGNAL13Low 0   // SIGNAL only Hight/Low PWM
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
int COUNTER = 0;
int THRESHOLD = 200;


void setup() {

  pinMode(SIGNAL0Low, OUTPUT);
  pinMode(SIGNAL1Low, OUTPUT);
  pinMode(SIGNAL2Low, OUTPUT);
  pinMode(SIGNAL3Low, OUTPUT);
  pinMode(SIGNAL4Low, OUTPUT);
  pinMode(SIGNAL5Low, OUTPUT);
  pinMode(SIGNAL6Low, OUTPUT);
  pinMode(SIGNAL7Low, OUTPUT);
  pinMode(SIGNAL8Low, OUTPUT);
  pinMode(SIGNAL9Low, OUTPUT);
  pinMode(SIGNAL10Low, OUTPUT);
  pinMode(SIGNAL11Low, OUTPUT);
  pinMode(SIGNAL12Low, OUTPUT);
  pinMode(SIGNAL13Low, OUTPUT);

  //TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM02);
  //TCCR0B = _BV(CS02);

  //TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM12);
  //TCCR1B = _BV(CS12);

  //TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM20);
  //TCCR2B = _BV(CS22);

  randomSeed(analogRead(A0) + analogRead(A1) + analogRead(A2));
}


void loop() {
  analogReference(EXTERNAL);

  if (COUNTER = 0) {
    randNumber = random(130, 1000);
    tone(SIGNAL9Low, randNumber, 1000);
    //analogWrite(SIGNAL9Low, randNumber);

    randNumber = random(130, 1000);
    tone(SIGNAL10Low, randNumber, 1000);
    //analogWrite(SIGNAL10Low, randNumber);

    randNumber = random(130, 1000);
    tone(SIGNAL11Low, randNumber, 1000);
    //analogWrite(SIGNAL11Low, randNumber);

    randNumber = random(130, 1000);
    tone(SIGNAL12Low, randNumber, 1000);
    //analogWrite(SIGNAL12Low, randNumber);
    COUNTER = 1;

  } else {
    randNumber = random(0, 130);
    tone(SIGNAL9Low, randNumber, 1000);
    //analogWrite(SIGNAL9Low, randNumber);

    randNumber = random(0, 130);
    tone(SIGNAL10Low, randNumber, 1000);
    //analogWrite(SIGNAL10Low, randNumber);

    randNumber = random(0, 130);
    tone(SIGNAL11Low, randNumber, 1000);
    //analogWrite(SIGNAL11Low, randNumber);

    randNumber = random(0, 130);
    tone(SIGNAL12Low, randNumber, 1000);
    //analogWrite(SIGNAL12Low, randNumber);
    COUNTER = 0;
  }

  randNumber = random(0, 255);
  analogWrite(SIGNAL0Low, randNumber);
  //randNumber = random(0, 180);
  //pinMode(SIGNAL9Low, OUTPUT);
  //pinMode(SIGNAL10Low, OUTPUT);

  //OCR0A = randNumber;
  //randNumber = random(0, 50);
  //OCR0B = randNumber;

  //randNumber = random(0, 180);
  //pinMode(SIGNAL11Low, OUTPUT);
  //pinMode(SIGNAL12Low, OUTPUT);

  //OCR1A = randNumber;
  //randNumber = random(0, 50);
  //OCR1B = randNumber;

  //randNumber = random(0, 190);
  //pinMode(SIGNAL4Low, OUTPUT);
  //pinMode(SIGNAL2Low, OUTPUT);

  //OCR2A = randNumber;
  //randNumber = random(0, 50);
  //OCR2B = randNumber;

  runrandomsignals();
}


void runrandomsignals() {

  randNumber = random(0, 255);
  delay_one_tenth_ms(20);
  analogWrite(SIGNAL1Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(20);
  analogWrite(SIGNAL2Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(20);
  analogWrite(SIGNAL3Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(20);
  analogWrite(SIGNAL4Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(20);
  analogWrite(SIGNAL5Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(20);
  analogWrite(SIGNAL6Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(20);
  analogWrite(SIGNAL7Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(20);
  analogWrite(SIGNAL8Low, randNumber);

  randNumber = random(0, 255);
  delay_one_tenth_ms(20);
  analogWrite(SIGNAL13Low, randNumber);

  //##################################################################

  randNumber = random(0, 255);
  analogWrite(SIGNAL1Low, randNumber);

  randNumber = random(0, 255);
  analogWrite(SIGNAL2Low, randNumber);

  randNumber = random(0, 255);
  analogWrite(SIGNAL3Low, randNumber);

  randNumber = random(0, 255);
  analogWrite(SIGNAL4Low, randNumber);

  randNumber = random(0, 255);
  analogWrite(SIGNAL5Low, randNumber);

  randNumber = random(0, 255);
  analogWrite(SIGNAL6Low, randNumber);

  randNumber = random(0, 255);
  analogWrite(SIGNAL7Low, randNumber);

  randNumber = random(0, 255);
  analogWrite(SIGNAL8Low, randNumber);

  randNumber = random(0, 255);
  analogWrite(SIGNAL13Low, randNumber);

  noTone(SIGNAL9Low);
  noTone(SIGNAL10Low);
  noTone(SIGNAL11Low);
  noTone(SIGNAL12Low);
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
