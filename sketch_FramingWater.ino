#include <Adafruit_NeoPixel.h>

// LED strip configuration
#define LED_PIN 2
#define NUM_PIXELS 37
#define BRIGHTNESS 10 //uses less power and isn't blinding for indoor play. Needs to be brighter to be played in full sun outdoors
Adafruit_NeoPixel strip(NUM_PIXELS, LED_PIN, NEO_GRBW + NEO_KHZ800);

//Buttons
const int buttonPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47}; // Button pin assignments
const int numButtons = 37;  // Number of buttons

void setup() {
  Serial.begin(9600);

  // Initialize buttons with internal Pullup resistors
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  for  (int i = 0; i < numButtons; i++) {
    Serial.println(digitalRead(buttonPins[i]));
  }

  delay(5000);
  // Initialize LED strip
  strip.begin();
  strip.setBrightness(BRIGHTNESS);

  // Turn all LEDs ON (blue)
  for (int i = 0; i < NUM_PIXELS; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 255));  // Blue color
  }
  strip.show();

  delay(200);
}

void loop() {
 int count = 0;


  //Read all buttons
  for (int i = 0; i < numButtons; i++) {
    if (digitalRead(buttonPins[i]) == LOW){

      count++;
    }
  }


    Serial.println(count);

    for (int i = 0; i < NUM_PIXELS; i++){
      if (i < count){
        strip.setPixelColor(i, strip.Color(0,0,0));
      }else{
        strip.setPixelColor(i, strip.Color(0,0,255));
      }
    }
    strip.show();
    delay(50);

}
