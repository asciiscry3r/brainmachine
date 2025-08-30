
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


unsigned long int randNumber = 0;
unsigned long int randNumberPrevious = 0;
unsigned long int randTimePrevious = 0;
unsigned long int randLimitInit = 0;
unsigned long int randLimitInitPrevious = 0;
unsigned long int randLimitEnd = 0;
unsigned long int randLimitEndPrevious = 0;
unsigned long int randNumber_130_previous = 0;
unsigned long int randNumber_1000_previous = 0;
unsigned long int randNumber_10000_previous = 0;
unsigned long int randNumber_20000_previous = 0;
unsigned long int randTime = 0;
unsigned long int COUNTER = 0;
unsigned long int randLimitFirst_Initial = 2;
unsigned long int randLimitSecond_Initial = 10;
unsigned long int randLimitFirst_End = 10;
unsigned long int randLimitSecond_End = 25;


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
  
  randomSeed(analogRead(A0)); // local ~putin~ faced police/millitia dont belive in addition, im IDK - we have this in many places
}


void loop() {

  //TEST = random(0, 180);
  //pinMode(SIGNAL9Low, OUTPUT);
  //pinMode(SIGNAL10Low, OUTPUT);

  //OCR0A = TEST;
  //TEST = random(0, 50);
  //OCR0B = TEST;

  //TEST = random(0, 180);
  //pinMode(SIGNAL11Low, OUTPUT);
  //pinMode(SIGNAL12Low, OUTPUT);

  //OCR1A = TEST;
  //TEST = random(0, 50);
  //OCR1B = TEST;

  //TEST = random(0, 190);
  //pinMode(SIGNAL4Low, OUTPUT);
  //pinMode(SIGNAL2Low, OUTPUT);

  //OCR2A = TEST;
  //OCR2B = TEST;

  rundomsound();

  runrandomsignals();

}


float randLimit_initial() {

  randLimitInit = random(randLimitFirst_Initial, randLimitSecond_Initial);
  
  if (randLimitInitPrevious != 0) {
    do {
      randLimitInit = random(randLimitFirst_Initial, randLimitFirst_Initial);
    } while (randLimitInitPrevious == randLimitInit);
  }
  randLimitInitPrevious = randLimitInit;

  return randLimitInit;
}


float randLimit_end() {

  randLimitEnd = random(randLimitFirst_End, randLimitSecond_End);
  
  if (randLimitEndPrevious != 0) {
    do {
      randLimitEnd = random(randLimitFirst_End, randLimitSecond_End);
    } while (randLimitEndPrevious == randLimitEnd);
  }
  randLimitEndPrevious = randTime;

  return randLimitEnd;
}


float randomtime() {

  randTime = random(randLimitInit, randLimitEnd);
  
  if (randTimePrevious != 0) {
    do {
      randTime = random(randLimitInit, randLimitEnd);
    } while (randTimePrevious == randTime);
  }
  randTimePrevious = randTime;

  return randTime;
}


float randomnumber() {

  randNumber = random(0, 255);

  if (randNumberPrevious != 0) {
    do {
      randNumber = random(0, 255);
    } while (randNumber == randNumberPrevious);
  }
  randNumberPrevious = randNumber;

  return randNumber;
}


void playtone_130(long int firstfreaquency, long int secondfreaquency) {

    long int randNumber_130;

    randNumber_130 = random(firstfreaquency, secondfreaquency);

    do {
      randNumber_130 = random(firstfreaquency, secondfreaquency);
    } while (randNumber_130_previous == randNumber_130);

    randNumber_130_previous = randNumber_130;

    tone(SIGNAL9Low, randNumber_130);
}


void playtone_1000(long int firstfreaquency, long int secondfreaquency) {

    long int randNumber_1000;

    randNumber_1000 = random(firstfreaquency, secondfreaquency);

    do {
      randNumber_1000 = random(firstfreaquency, secondfreaquency);
    } while (randNumber_1000_previous == randNumber_1000);

    randNumber_1000_previous = randNumber_1000;

    tone(SIGNAL9Low, randNumber_1000);
}


void playtone_10000(long int firstfreaquency, long int secondfreaquency) {

    long int randNumber_10000;

    randNumber_10000 = random(firstfreaquency, secondfreaquency);

    do {
      randNumber_10000 = random(firstfreaquency, secondfreaquency);
    } while (randNumber_10000_previous == randNumber_10000);

    randNumber_10000_previous = randNumber_10000;

    tone(SIGNAL9Low, randNumber_10000);
}


void playtone_20000(long int firstfreaquency, long int secondfreaquency) {
    
    long int randNumber_20000;

    randNumber_20000 = random(firstfreaquency, secondfreaquency);

    do {
      randNumber_20000 = random(firstfreaquency, secondfreaquency);
    } while (randNumber_20000_previous == randNumber_20000);

    randNumber_20000_previous = randNumber_20000;

    tone(SIGNAL9Low, randNumber_20000);
}


void rundomsound() {

  if (COUNTER = 0) {

    playtone_1000(130, 1000);
    randTime = randomtime();
    delay_one_tenth_ms(randTime);

    noTone(SIGNAL9Low);

    playtone_10000(1000, 10000);
    randTime = randomtime();
    delay_one_tenth_ms(randTime);

    noTone(SIGNAL9Low);

    COUNTER = 1;

  } else {

    playtone_20000(10000, 20000);
    randTime = randomtime();
    delay_one_tenth_ms(randTime);

    noTone(SIGNAL9Low);

    playtone_130(0, 130);
    randTime = randomtime();
    delay_one_tenth_ms(randTime);

    noTone(SIGNAL9Low);

    COUNTER = 0;
  }
  return COUNTER;
}


void runrandomsignals() {

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL0Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL1Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL2Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL3Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL4Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL5Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL6Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL7Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL8Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL13Low, randNumber);
  delay_one_tenth_ms(randTime);

  //TEST = random(0, 255);
  //delay_one_tenth_ms(20);
  //analogWrite(SIGNAL9Low, randNumber);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL10Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL11Low, randNumber);
  delay_one_tenth_ms(randTime);

  randNumber = randomnumber();
  randTime = randomtime();
  analogWrite(SIGNAL12Low, randNumber);
  delay_one_tenth_ms(randTime);

  //##################################################################

  randNumber = randomnumber();
  analogWrite(SIGNAL0Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL1Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL2Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL3Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL4Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL5Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL6Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL7Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL8Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL13Low, randNumber);

  //TEST = random(0, 255);
  //analogWrite(SIGNAL9Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL10Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL11Low, randNumber);

  randNumber = randomnumber();
  analogWrite(SIGNAL12Low, randNumber);
}


void delay_one_tenth_ms(unsigned long int ms) {
  unsigned long int timer;
  const unsigned long int DelayCount = 93;  // Default: 87 - this value was determined by trial and error

  while (ms != 0) {
    // Toggling PD0 is done here to force the compiler to do this loop, rather than optimize it away
    for (timer = 0; timer <= DelayCount; timer++) { PIND |= 0b0000001; };
    ms--;
  }
}
