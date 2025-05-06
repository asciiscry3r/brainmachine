//#include <avr/pgmspace.h>  // for arrays - PROGMEM
//#include <avr/sleep.h>     // A library to control the sleep mode
//#include <avr/power.h>     // A library to control power

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


  randomSeed(analogRead(A0) + analogRead(A1) + analogRead(A2));
}


void loop() {
  analogReference(EXTERNAL);
  runrandomsignals();

  randNumber = random(0, 200);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL0Low, randNumber);

  //currentMillis = millis();
  //SIGNAL4Low = (analogRead(A2) / 4);
  //switchInterval = random(1000, 3000);
  //switchDuration = random(1000, 3000);
  //switch_rele();
  randNumber = random(100, 10000);
  analogWrite(SIGNAL0Low, randNumber);
  delay_one_tenth_ms(10);
  randNumber = random(10000, 200000);
  analogWrite(SIGNAL0Low, randNumber);

  delay_one_tenth_ms(10);
}


//========================================

void switch_rele() {  // Must be "Clock" on NE555 with, 1kOm/1kOm + 1mkF, Old/Current on 1kOm/1kOm + 1000mkF
  int value = analogRead(3);
  if ((value / 4) > THRESHOLD) {
    if (COUNTER == 32767) {
      COUNTER = 0;
    } else {
      COUNTER = COUNTER++;
    }
    randNumber = random(100, 600);
    if (COUNTER > randNumber) {
      analogWrite(SIGNAL4Low, 255);
    }
  } else {
    analogWrite(SIGNAL4Low, 0);
  }
}
//   if (currentMillis == switchDuration) {
//     if (port_level == 255) {
//       analogWrite(SIGNAL6Low, 0);
//       port_level = 0;
//     } else {
//       analogWrite(SIGNAL6Low, 255);
//       port_level = 255;
//     }
//   } else {
//     analogWrite(SIGNAL6Low, 255);
//     port_level = 255;
//   }
//   return switchDuration;
// }


void runrandomsignals() {
  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL1Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL2Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL3Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL4Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL5Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL6Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL7Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL8Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL9Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL10Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL11Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL12Low, randNumber);

  randNumber = random(0, 200);
  delay_one_tenth_ms(11);
  analogWrite(SIGNAL13Low, randNumber);
  /////////////////////////////////////////////////////////
  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL1Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL2Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL3Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL4Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL5Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL6Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL7Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL8Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL9Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL10Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL11Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL12Low, randNumber);

  randNumber = random(10000, 20000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL13Low, randNumber);
/////////////////////////////////////
  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL1Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL2Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL3Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL4Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL5Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL6Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL7Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL8Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL9Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL10Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL11Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL12Low, randNumber);

  randNumber = random(100, 10000);
  delay_one_tenth_ms(1);
  analogWrite(SIGNAL13Low, randNumber);
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
