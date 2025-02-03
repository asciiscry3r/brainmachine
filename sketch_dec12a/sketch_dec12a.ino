
/***************************************************
SOME INFORMATION ABOUT PROGMEM:
First, you have to use #include <avr/pgmspace.h> for table arrays - PROGMEM
The Arduino compiler creates code that will transfer all constants into RAM when the microcontroller
resets.  This hardward could probably hold all this data in memory, but since the original system
used a table (brainwaveTab) that is was too large to transfer into RAM in the original microcontroller,
we're taking the same approach.  This is accomplished by using the library for PROGMEM. 
(This is used below in the definition for the brainwaveTab).  Since the
C compiler assumes that constants are in RAM, rather than in program memory, when accessing
the brainwaveTab, we need to use the pgm_read_byte() and pgm_read_dword() macros, and we need
to use the brainwveTab as an address, i.e., precede it with "&".  For example, to access
brainwaveTab[3].bwType, which is a byte, this is how to do it:
     pgm_read_byte( &brainwaveTab[3].bwType );
And to access brainwaveTab[3].bwDuration, which is a double-word, this is how to do it:
     pgm_read_dword( &brainwaveTab[3].bwDuration );
 ***************************************************/


#include <avr/pgmspace.h>  // for arrays - PROGMEM
#include <Tone.h>          // Include the arduino tone library
#include <avr/sleep.h>     // A library to control the sleep mode
#include <avr/power.h>     // A library to control power


#define rightEyeRed 5   // Define pinout for right eye
#define leftEyeRed 6    // Define pinout for left eye
#define rightEarLow 9   // Define pinout for left ear
#define lefttEarLow 10  // Define pinout for left ear
#define SIGNAL1Low 8       // SIGNAL
#define SIGNAL2Low 11      // SIGNAL
#define SIGNAL3Low 4       // SIGNAL
#define SIGNAL4Low 3       // SIGNAL
#define SIGNAL5Low 7       // SIGNAL
#define SIGNAL6Low 1       // SIGNAL
#define SIGNAL7Low 12      // SIGNAL
#define SIGNAL8Low 13      // SIGNAL


struct brainwaveElement {
  char bwType;  // 'a' for Alpha, 'b' for Beta, 't' for Theta,'d' for Delta or 'g' for gamma ('0' signifies last entry in table
  // A, B, T, D and G offer alternating flash instead of concurrent flash.
  unsigned long int bwDuration;  // Duration of this Brainwave Type (divide by 10,000 to get seconds)
} const brainwaveTab[] PROGMEM = {
  { 'b', 600000 },
  { 'a', 100000 },
  { 'b', 200000 },
  { 'a', 150000 },
  { 'b', 150000 },
  { 'a', 200000 },
  { 'b', 100000 },
  { 'a', 300000 },
  { 'b', 50000 },
  { 'a', 600000 },
  { 't', 100000 },
  { 'a', 300000 },
  { 't', 200000 },
  { 'a', 300000 },
  { 't', 300000 },
  { 'a', 150000 },
  { 't', 600000 },
  { 'a', 150000 },
  { 'b', 10000 },
  { 'a', 150000 },
  { 't', 600000 },
  { 'd', 10000 },
  { 't', 100000 },
  { 'd', 10000 },
  { 't', 100000 },
  { 'd', 10000 },
  { 't', 300000 },
  { 'a', 150000 },
  { 'b', 10000 },
  { 'a', 150000 },
  { 't', 300000 },
  { 'a', 150000 },
  { 'b', 10000 },
  { 'a', 200000 },
  { 'b', 50000 },
  { 'a', 200000 },
  { 'b', 150000 },
  { 'a', 150000 },
  { 'b', 200000 },
  { 'a', 100000 },
  { 'b', 250000 },
  { 'a', 50000 },
  { 'b', 600000 },
  { '0', 0 }
};


float binauralBeat[] = { 14.4, 11.1, 6.0, 2.2, 40.4 };  // For beta, alpha, gamma and delta beat differences.
Tone rightEar;
Tone leftEar;
Tone SIGNAL1;
Tone SIGNAL2;
Tone SIGNAL3;
Tone SIGNAL4;
Tone SIGNAL5;
Tone SIGNAL6;
Tone SIGNAL7;
float centralTone = 440.0;  //We're starting at this tone and spreading the binaural beat from there.

long randNumber;

//Blink statuses for function 'blink_LEDs' and 'alt_blink_LEDS
unsigned long int duration = 0;
unsigned long int onTime = 0;
unsigned long int offTime = 0;

const int buttonPin = 2;  // the number of the pushbutton pin
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int ledState = LOW;

void setup() {
  rightEar.begin(rightEarLow);  // Tone rightEar begins at pin output rightEarLow
  leftEar.begin(lefttEarLow);   // Tone leftEar begins at pin output leftEarLow
  SIGNAL1.begin(SIGNAL1Low);
  SIGNAL2.begin(SIGNAL2Low);
  SIGNAL3.begin(SIGNAL3Low);
  SIGNAL4.begin(SIGNAL4Low);
  SIGNAL5.begin(SIGNAL5Low);
  SIGNAL6.begin(SIGNAL6Low);
  SIGNAL7.begin(SIGNAL7Low);
  pinMode(rightEyeRed, OUTPUT);  // Pin output at rightEyeRed
  pinMode(leftEyeRed, OUTPUT);   // Pin output at leftEyeRed
}


void loop() {
  analogReference(EXTERNAL);
  checkbuttonstate();
  runrandomsignals();
  switch (buttonState) {
    case LOW:
      {
        delay(2000);
        rightEar.stop();
        leftEar.stop();
        runbrainprogram();
      }
      break;
    default:
      {
        runrandomnoise();
        checkbuttonstate();
      }
      break;
  }
  checkbuttonstate();
  delay_one_tenth_ms(10);
  digitalWrite(SIGNAL8Low, ledState = ledState ? LOW: HIGH);
}


void checkbuttonstate() {
  buttonState = digitalRead(buttonPin);
  return buttonState;
}


void runrandomsignals() {
  randomSeed(analogRead(A0) + analogRead(A2) + analogRead(A3) + analogRead(A4) + analogRead(A1) + analogRead(A5) + analogRead(A6));
  //analogWrite(SIGNAL1, 0);
  randNumber = random(0, 255);
  //analogWrite(SIGNAL1, randNumber);
  delay_one_tenth_ms(10);
  SIGNAL1.play(randNumber);
  randomSeed(analogRead(A1) + analogRead(A3) + analogRead(A2) + analogRead(A0) + analogRead(A4) + analogRead(A6) + analogRead(A5));
  //analogWrite(SIGNAL2, 0);
  randNumber = random(0, 255);
  //analogWrite(SIGNAL2, randNumber);
  delay_one_tenth_ms(10);
  SIGNAL2.play(randNumber);
  randomSeed(analogRead(A0) + analogRead(A4) + analogRead(A3) + analogRead(A2) + analogRead(A1) + analogRead(A6) + analogRead(A5));
  //analogWrite(SIGNAL3, 0);
  randNumber = random(0, 255);
  //analogWrite(SIGNAL3, randNumber);
  delay_one_tenth_ms(10);

  SIGNAL3.play(randNumber);
  randomSeed(analogRead(A3) + analogRead(A0) + analogRead(A2) + analogRead(A1) + analogRead(A4) + analogRead(A5) + analogRead(A6));
  //analogWrite(SIGNAL4, 0);
  randNumber = random(0, 255);
  //analogWrite(SIGNAL4, randNumber);
  delay_one_tenth_ms(10);

  SIGNAL4.play(randNumber);
  randomSeed(analogRead(A0) + analogRead(A2) + analogRead(A3) + analogRead(A4) + analogRead(A1) + analogRead(A5) + analogRead(A6));
  //analogWrite(SIGNAL1, 0);
  randNumber = random(0, 255);
  //analogWrite(SIGNAL1, randNumber);
  delay_one_tenth_ms(10);

  SIGNAL5.play(randNumber);
  randomSeed(analogRead(A1) + analogRead(A3) + analogRead(A2) + analogRead(A0) + analogRead(A4) + analogRead(A6) + analogRead(A5));
  //analogWrite(SIGNAL2, 0);
  randNumber = random(0, 255);
  //analogWrite(SIGNAL2, randNumber);
  delay_one_tenth_ms(10);

  SIGNAL6.play(randNumber);
  randomSeed(analogRead(A0) + analogRead(A4) + analogRead(A3) + analogRead(A2) + analogRead(A1) + analogRead(A6) + analogRead(A5));
  //analogWrite(SIGNAL3, 0);
  randNumber = random(0, 255);
  //analogWrite(SIGNAL3, randNumber);
  delay_one_tenth_ms(10);

  SIGNAL7.play(randNumber);
}


void runrandomnoise() {
  randomSeed(analogRead(A0) + analogRead(A4) + analogRead(A4) + analogRead(A3) + analogRead(A1) + analogRead(A5) + analogRead(A6));

  randNumber = random(80);
  rightEar.play(randNumber);
  analogWrite(rightEyeRed, 0);   // common anode -
  analogWrite(leftEyeRed, 255);  // LOW means 'on'
  // turn on LEDs

  analogWrite(rightEyeRed, 255);  // common anode -
  analogWrite(leftEyeRed, 0);     // HIGH means 'off'
  delay_one_tenth_ms(10);


  randomSeed(analogRead(A4) + analogRead(A1) + analogRead(A0) + analogRead(A3) + analogRead(A2) + analogRead(A6) + analogRead(A5));

  randNumber = random(80);
  leftEar.play(randNumber);
  analogWrite(rightEyeRed, 0);   // common anode -
  analogWrite(leftEyeRed, 255);  // LOW means 'on'
  // turn on LEDs

  analogWrite(rightEyeRed, 255);  // common anode -
  analogWrite(leftEyeRed, 0);     // HIGH means 'off'
  delay_one_tenth_ms(10);
}


void runbrainprogram() {
  int j = 0;
  while (pgm_read_byte(&brainwaveTab[j].bwType) != '0') {  // '0' signifies end of table
    do_brainwave_element(j);
    j++;
    analogWrite(rightEyeRed, 255);  // common anode -
    analogWrite(leftEyeRed, 255);   // HIGH means 'off'
    rightEar.stop();
    leftEar.stop();
  }
}

/***************************************************
This function delays the specified number of 1/10 milliseconds
***************************************************/

void delay_one_tenth_ms(unsigned long int ms) {
  unsigned long int timer;
  const unsigned long int DelayCount = 196;  // Default: 87 - this value was determined by trial and error

  while (ms != 0) {
    // Toggling PD0 is done here to force the compiler to do this loop, rather than optimize it away
    for (timer = 0; timer <= DelayCount; timer++) { PIND |= 0b0000001; };
    ms--;
  }
}


void blink_LEDs(unsigned long int duration, unsigned long int onTime, unsigned long int offTime) {
  for (int i = 0; i < (duration / (onTime + offTime)); i++) {
    analogWrite(rightEyeRed, 0);  // common anode -
    analogWrite(leftEyeRed, 0);   // LOW means 'on'
    // turn on LEDs
    delay_one_tenth_ms(onTime);  //   for onTime

    analogWrite(rightEyeRed, 255);  // common anode -
    analogWrite(leftEyeRed, 255);   // HIGH means 'off'
                                    // turn off LEDs
    delay_one_tenth_ms(offTime);    //   for offTime
  }
}

void alt_blink_LEDs(unsigned long int duration, unsigned long int onTime, unsigned long int offTime) {
  for (int i = 0; i < (duration / (onTime + offTime)); i++) {
    analogWrite(rightEyeRed, 0);   // common anode -
    analogWrite(leftEyeRed, 255);  // LOW means 'on'
    // turn on LEDs
    delay_one_tenth_ms(onTime);  //   for onTime

    analogWrite(rightEyeRed, 255);  // common anode -
    analogWrite(leftEyeRed, 0);     // HIGH means 'off'
                                    // turn off LEDs
    delay_one_tenth_ms(offTime);    //   for offTime
  }
}


void do_brainwave_element(int index) {
  char brainChr = pgm_read_byte(&brainwaveTab[index].bwType);

  switch (brainChr) {
    case 'b':
      // Beta
      checkbuttonstate();
      rightEar.play(centralTone - (binauralBeat[0] / 2));
      leftEar.play(centralTone + (binauralBeat[0] / 2));
      // stoptoneandleds(buttonState);
      //  Generate binaural beat of 14.4Hz
      //  delay for the time specified in the table while blinking the LEDs at the correct rate
      blink_LEDs(pgm_read_dword(&brainwaveTab[index].bwDuration), 347, 347);
      return;  // Beta

    case 'B':
      // Beta - with alternating blinks
      checkbuttonstate();
      rightEar.play(centralTone - (binauralBeat[0] / 2));
      leftEar.play(centralTone + (binauralBeat[0] / 2));
      // stoptoneandleds(buttonState);
      //  Generate binaural beat of 14.4Hz
      //  delay for the time specified in the table while blinking the LEDs at the correct rate
      alt_blink_LEDs(pgm_read_dword(&brainwaveTab[index].bwDuration), 347, 347);
      return;  // Beta - with alternating blinks

    case 'a':
      // Alpha
      checkbuttonstate();
      rightEar.play(centralTone - (binauralBeat[1] / 2));
      leftEar.play(centralTone + (binauralBeat[1] / 2));
      // stoptoneandleds(buttonState);
      // Generates a binaural beat of 11.1Hz
      // delay for the time specified in the table while blinking the LEDs at the correct rate
      blink_LEDs(pgm_read_dword(&brainwaveTab[index].bwDuration), 451, 450);
      return;  // Alpha

    case 'A':
      // Alpha
      checkbuttonstate();
      rightEar.play(centralTone - (binauralBeat[1] / 2));
      leftEar.play(centralTone + (binauralBeat[1] / 2));
      // stoptoneandleds(buttonState);
      // Generates a binaural beat of 11.1Hz
      // delay for the time specified in the table while blinking the LEDs at the correct rate
      alt_blink_LEDs(pgm_read_dword(&brainwaveTab[index].bwDuration), 451, 450);
      return;  // Alpha - with alternating blinks

    case 't':
      // Theta
      checkbuttonstate();
      // start Timer 1 with the correct Offset Frequency for a binaural beat for the Brainwave Type
      //   to Right ear speaker through output OC1A (PB3, pin 15)
      rightEar.play(centralTone - (binauralBeat[2] / 2));
      leftEar.play(centralTone + (binauralBeat[2] / 2));
      // stoptoneandleds(buttonState);
      // Generates a binaural beat of 6.0Hz
      // delay for the time specified in the table while blinking the LEDs at the correct rate
      blink_LEDs(pgm_read_dword(&brainwaveTab[index].bwDuration), 835, 835);
      return;  // Theta

    case 'T':
      // Theta
      checkbuttonstate();
      // start Timer 1 with the correct Offset Frequency for a binaural beat for the Brainwave Type
      //   to Right ear speaker through output OC1A (PB3, pin 15)
      rightEar.play(centralTone - (binauralBeat[2] / 2));
      leftEar.play(centralTone + (binauralBeat[2] / 2));
      // stoptoneandleds(buttonState);
      // Generates a binaural beat of 6.0Hz
      // delay for the time specified in the table while blinking the LEDs at the correct rate
      alt_blink_LEDs(pgm_read_dword(&brainwaveTab[index].bwDuration), 835, 835);
      return;  // Theta - with alternating blinks

    case 'd':
      // Delta
      checkbuttonstate();
      rightEar.play(centralTone - (binauralBeat[3] / 2));
      leftEar.play(centralTone + (binauralBeat[3] / 2));
      // stoptoneandleds(buttonState);

      // Generates a binaural beat of 2.2Hz
      // delay for the time specified in the table while blinking the LEDs at the correct rate
      blink_LEDs(pgm_read_dword(&brainwaveTab[index].bwDuration), 2253, 2253);
      return;  // Delta

    case 'D':
      // Delta
      checkbuttonstate();
      rightEar.play(centralTone - (binauralBeat[3] / 2));
      leftEar.play(centralTone + (binauralBeat[3] / 2));
      // stoptoneandleds(buttonState);

      // Generates a binaural beat of 2.2Hz
      // delay for the time specified in the table while blinking the LEDs at the correct rate
      alt_blink_LEDs(pgm_read_dword(&brainwaveTab[index].bwDuration), 2253, 2253);
      return;  // Delta

    case 'g':
      // Gamma
      checkbuttonstate();
      rightEar.play(centralTone - (binauralBeat[4] / 2));
      leftEar.play(centralTone + (binauralBeat[4] / 2));
      // stoptoneandleds(buttonState);
      // Generates a binaural beat of 40.4Hz
      // delay for the time specified in the table while blinking the LEDs at the correct rate
      blink_LEDs(pgm_read_dword(&brainwaveTab[index].bwDuration), 124, 124);
      return;  // Gamma

    case 'G':
      // Gamma
      checkbuttonstate();
      rightEar.play(centralTone - (binauralBeat[4] / 2));
      leftEar.play(centralTone + (binauralBeat[4] / 2));
      // stoptoneandleds(buttonState);

      // Generates a binaural beat of 40.4Hz
      // delay for the time specified in the table while blinking the LEDs at the correct rate
      alt_blink_LEDs(pgm_read_dword(&brainwaveTab[index].bwDuration), 124, 124);
      return;  // Gamma

    // this should never be executed, since we catch the end of table in the main loop
    default:
      return;  // end of table
  }
}


void sleepNow()  // here we put the arduino to sleep
{
  /* Now is the time to set the sleep mode. In the Atmega8 datasheet
     * http://www.atmel.com/dyn/resources/prod_documents/doc2486.pdf on page 35
     * there is a list of sleep modes which explains which clocks and 
     * wake up sources are available in which sleep mode.
     *
     * In the avr/sleep.h file, the call names of these sleep modes are to be found:
     *
     * The 5 different modes are:
     *     SLEEP_MODE_IDLE         -the least power savings 
     *     SLEEP_MODE_ADC
     *     SLEEP_MODE_PWR_SAVE
     *     SLEEP_MODE_STANDBY
     *     SLEEP_MODE_PWR_DOWN     -the most power savings
     *
     * For now, we want as much power savings as possible, so we 
     * choose the according 
     * sleep mode: SLEEP_MODE_PWR_DOWN
     * 
     */
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  // sleep mode is set here

  sleep_enable();  // enables the sleep bit in the mcucr register
                   // so sleep is possible. just a safety pin

  /* Now it is time to enable an interrupt. We do it here so an 
     * accidentally pushed interrupt button doesn't interrupt 
     * our running program. if you want to be able to run 
     * interrupt code besides the sleep function, place it in 
     * setup() for example.
     * 
     * In the function call attachInterrupt(A, B, C)
     * A   can be either 0 or 1 for interrupts on pin 2 or 3.   
     * 
     * B   Name of a function you want to execute at interrupt for A.
     *
     * C   Trigger mode of the interrupt pin. can be:
     *             LOW        a low level triggers
     *             CHANGE     a change in level triggers
     *             RISING     a rising edge of a level triggers
     *             FALLING    a falling edge of a level triggers
     *
     * In all but the IDLE sleep modes only LOW can be used.
     */

  attachInterrupt(0, wakeUpNow, LOW);  // use interrupt 0 (pin 2) and run function
                                       // wakeUpNow when pin 2 gets LOW

  sleep_mode();  // here the device is actually put to sleep!!
                 // THE PROGRAM CONTINUES FROM HERE AFTER WAKING UP

  sleep_disable();     // first thing after waking from sleep:
                       // disable sleep...
  detachInterrupt(0);  // disables interrupt 0 on pin 2 so the
                       // wakeUpNow code will not be executed
                       // during normal running time.
}

/***************************************************
WAKE function
***************************************************/
void wakeUpNow()  // here the interrupt is handled after wakeup
{
  // execute code here after wake-up before returning to the loop() function
  // timers and code using timers (serial.print and more...) will not work here.
  // we don't really need to execute any special functions here, since we
  // just want the thing to wake up
}

/***************************************************
Timer function - millisecond count is sent to serial monitor at start
of the show and again just before sleeping. Make the milliseconds match
as closely as possible to the sum of bwDuration column. This is achieved
by changing delayCount. delayCount from Mitch Altman's original sketch
was at 87. But we're using a faster chip, so I've determined for the 
arduino delayCount should be somewhere around 196.
***************************************************/
void myTimer() {
  Serial.println("  ");
  Serial.print("Time: ");
  long int time = millis();
  //prints time since program started
  Serial.print(time);
  Serial.println("  ");
  // This function is a little quirky, but it works.
}
