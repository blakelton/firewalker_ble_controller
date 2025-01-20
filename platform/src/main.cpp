#include <Arduino.h>

// By default, on Seeed XIAO BLE (Sense) boards, the onboard APA102 LED is on:
//   - DATA  = pin 13
//   - CLOCK = pin 14
#define DOTSTAR_DATA_PIN  13
#define DOTSTAR_CLOCK_PIN 14

// Send one byte out via bit-bang on the DotStar pins
void sendByte(uint8_t b) {
  for (uint8_t i = 0; i < 8; i++) {
    digitalWrite(DOTSTAR_DATA_PIN, (b & 0x80) ? HIGH : LOW);
    digitalWrite(DOTSTAR_CLOCK_PIN, HIGH);
    b <<= 1;
    digitalWrite(DOTSTAR_CLOCK_PIN, LOW);
  }
}

// Send color (R,G,B) to the single onboard DotStar
// APA102 typically transmits in the order: StartFrame -> (Brightness),(B),(G),(R) -> EndFrame
void showColor(uint8_t r, uint8_t g, uint8_t b) {
  // Start frame: 4 bytes of 0x00
  sendByte(0x00);
  sendByte(0x00);
  sendByte(0x00);
  sendByte(0x00);

  // LED frame: 1st byte is global brightness (0xFF = max).
  sendByte(0xFF);
  // Next 3 bytes are B, G, R
  sendByte(b);
  sendByte(g);
  sendByte(r);

  // End frame: for one LED, 4 bytes of 0xFF is sufficient
  sendByte(0xFF);
  sendByte(0xFF);
  sendByte(0xFF);
  sendByte(0xFF);
}

void setup() {
  // Configure pins for output
  pinMode(DOTSTAR_DATA_PIN, OUTPUT);
  pinMode(DOTSTAR_CLOCK_PIN, OUTPUT);

  // Turn off the LED initially
  showColor(0, 0, 0);
}

void loop() {
  // Red for 1s
  showColor(255, 0, 0);
  delay(1000);

  // Green for 1s
  showColor(0, 255, 0);
  delay(1000);

  // Blue for 1s
  showColor(0, 0, 255);
  delay(1000);

  // Off for 1s
  showColor(0, 0, 0);
  delay(1000);
}
