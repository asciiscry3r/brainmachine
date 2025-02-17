#include <avr/pgmspace.h>  // for arrays - PROGMEM
//#include <Tone.h>          // Include the arduino tone library
#include <avr/sleep.h>  // A library to control the sleep mode
#include <avr/power.h>  // A library to control power


#define rightEyeRed 5   // Define pinout for right eye
#define leftEyeRed 6    // Define pinout for left eye
#define rightEarLow 9   // Define pinout for left ear
#define lefttEarLow 10  // Define pinout for left ear
#define SIGNAL1Low 8    // SIGNAL only PWM
#define SIGNAL2Low 11   // SIGNAL
#define SIGNAL3Low 4    // SIGNAL only PWM
#define SIGNAL4Low 3    // SIGNAL
#define SIGNAL5Low 7    // SIGNAL only PWM
#define SIGNAL6Low 1    // SIGNAL only PWM
#define SIGNAL7Low 12   // SIGNAL only PWM
#define SIGNAL8Low 13   // SIGNAL only PWM


//float binauralBeat[] = { 14.4, 11.1, 6.0, 2.2, 40.4 };  // For beta, alpha, gamma and delta beat differences.
//Tone rightEar;
//Tone leftEar;

//Tone SIGNAL2;
//Tone SIGNAL4;

//float centralTone = 440.0;  //We're starting at this tone and spreading the binaural beat from there.

long randNumber;

//Blink statuses for function 'blink_LEDs' and 'alt_blink_LEDS
unsigned long int duration = 0;
unsigned long int onTime = 0;
unsigned long int offTime = 0;

//const int buttonPin = 2;  // the number of the pushbutton pin
// variables will change:
//int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  //rightEar.begin(rightEarLow);  // Tone rightEar begins at pin output rightEarLow
  //leftEar.begin(lefttEarLow);   // Tone leftEar begins at pin output leftEarLow
  //SIGNAL2.begin(SIGNAL2Low);
  //SIGNAL4.begin(SIGNAL4Low);

  pinMode(SIGNAL1Low, OUTPUT);
  pinMode(SIGNAL3Low, OUTPUT);
  pinMode(SIGNAL5Low, OUTPUT);
  pinMode(SIGNAL6Low, OUTPUT);
  pinMode(SIGNAL7Low, OUTPUT);
  pinMode(SIGNAL8Low, OUTPUT);

  pinMode(rightEyeRed, OUTPUT);  // Pin output at rightEyeRed
  pinMode(leftEyeRed, OUTPUT);   // Pin output at leftEyeRed
}


void loop() {
  analogReference(EXTERNAL);
  checkbuttonstate();
  runrandomsignals();
  //        runrandomnoise();

  checkbuttonstate();
  delay_one_tenth_ms(10);
}


void checkbuttonstate() {
  buttonState = digitalRead(buttonPin);
  return buttonState;
}


void runrandomsignals() {
  randomSeed(analogRead(A0) + analogRead(A2) + analogRead(A3) + analogRead(A4) + analogRead(A1) + analogRead(A5));
  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL1Low, randNumber);

  randomSeed(analogRead(A1) + analogRead(A3) + analogRead(A2) + analogRead(A0) + analogRead(A4) + analogRead(A5));
  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  //SIGNAL2.play(randNumber);

  randomSeed(analogRead(A0) + analogRead(A4) + analogRead(A3) + analogRead(A2) + analogRead(A1) + analogRead(A5));
  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL3Low, randNumber);

  randomSeed(analogRead(A3) + analogRead(A0) + analogRead(A2) + analogRead(A1) + analogRead(A4) + analogRead(A5));
  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  //SIGNAL4.play(randNumber);

  randomSeed(analogRead(A0) + analogRead(A2) + analogRead(A3) + analogRead(A4) + analogRead(A1) + analogRead(A5));
  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL5Low, randNumber);

  randomSeed(analogRead(A1) + analogRead(A3) + analogRead(A2) + analogRead(A0) + analogRead(A4) + analogRead(A5));
  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL6Low, randNumber);

  randomSeed(analogRead(A0) + analogRead(A4) + analogRead(A3) + analogRead(A2) + analogRead(A1) + analogRead(A5));
  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL7Low, randNumber);

  randomSeed(analogRead(A0) + analogRead(A4) + analogRead(A3) + analogRead(A5) + analogRead(A1) + analogRead(A2));
  randNumber = random(0, 255);
  delay_one_tenth_ms(10);
  analogWrite(SIGNAL8Low, randNumber);
}


void runrandomnoise() {
  randomSeed(analogRead(A0) + analogRead(A4) + analogRead(A4) + analogRead(A3) + analogRead(A1) + analogRead(A5));

  randNumber = random(80);
  //rightEar.play(randNumber);
  analogWrite(rightEyeRed, 0);   // common anode -
  analogWrite(leftEyeRed, 255);  // LOW means 'on'
  delay_one_tenth_ms(10);
  // turn on LEDs

  analogWrite(rightEyeRed, 255);  // common anode -
  analogWrite(leftEyeRed, 0);     // HIGH means 'off'
  delay_one_tenth_ms(10);

  randomSeed(analogRead(A4) + analogRead(A1) + analogRead(A0) + analogRead(A3) + analogRead(A2) + analogRead(A5));

  randNumber = random(80);
  //leftEar.play(randNumber);
  analogWrite(rightEyeRed, 0);   // common anode -
  analogWrite(leftEyeRed, 255);  // LOW means 'on'
  delay_one_tenth_ms(10);
  // turn on LEDs

  analogWrite(rightEyeRed, 255);  // common anode -
  analogWrite(leftEyeRed, 0);     // HIGH means 'off'
  delay_one_tenth_ms(10);
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
