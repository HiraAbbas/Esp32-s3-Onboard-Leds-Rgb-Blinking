//// TX & RX onboard LED blinking using GPIO43 and GPIO44 /////
//// EXAMPLE 1///////////

#include <Arduino.h>

// These pins are normally used for UART.
// We can use them as normal GPIOs if we don't use Serial.print
#define TX_LED_PIN 43
#define RX_LED_PIN 44

void setup()
{
  // DO NOT call Serial.begin() if you want full control of these pins for blinking.
  // If you use Serial.begin(), the LEDs might flicker with serial data.
  pinMode(TX_LED_PIN, OUTPUT);
  pinMode(RX_LED_PIN, OUTPUT);
}

void loop()
{
  // TX LED ON
  digitalWrite(TX_LED_PIN, HIGH);
  digitalWrite(RX_LED_PIN, LOW);
  delay(500);

  // RX LED ON
  digitalWrite(TX_LED_PIN, LOW);
  digitalWrite(RX_LED_PIN, HIGH);
  delay(500);
}


//// Onboard RGB (NeoPixel) LED blinking using GPIO48 ///////
//// EXAMPLE 2///////////

// #include <Arduino.h>
// #include <Adafruit_NeoPixel.h>

// // Use the built-in NeoPixel pin
// Adafruit_NeoPixel onboardPixel(1, 48, NEO_GRB + NEO_KHZ800);

// void setup()
// {
//   onboardPixel.begin();
//   onboardPixel.setBrightness(50); // 0-255
// }

// void loop()
// {
//   onboardPixel.setPixelColor(0, 0xFF0000); // Red
//   onboardPixel.show();
//   delay(500);
//   onboardPixel.setPixelColor(0, 0x00FF00); // Green
//   onboardPixel.show();
//   delay(500);
//   onboardPixel.setPixelColor(0, 0x0000FF); // Blue
//   onboardPixel.show();
//   delay(500);
// }

