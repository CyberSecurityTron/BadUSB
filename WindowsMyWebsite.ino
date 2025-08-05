#include <DigiKeyboard.h>

#define LED_PIN 1
#define SHIFT   0x80

void typeText(const char *text) {
  while (*text) {
    uint8_t c        = (uint8_t)*text++;
    uint8_t code     = pgm_read_byte(&ascii_to_scan_code_table[c]);
    uint8_t modifier = 0;

    if (code & SHIFT) {
      modifier = MOD_SHIFT_LEFT;
      code    &= ~SHIFT;
    }

    if (code) {
      DigiKeyboard.sendKeyStroke(code, modifier);
      DigiKeyboard.delay(20);
    }
  }
}

void typeLine(const char *text) {
  typeText(text);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  typeLine("cmd");
  DigiKeyboard.delay(800);

  DigiKeyboard.delay(300);
  typeLine("color 0a");
  typeLine("echo Artefact was here :)");
  DigiKeyboard.delay(300);
  typeLine("start https://www.youtube.com/watch?v=y6120QOlsfU");
  DigiKeyboard.delay(800);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  typeLine("https://www.artefactlab.me");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(800);
  digitalWrite(LED_PIN, LOW);
  delay(800);
}
