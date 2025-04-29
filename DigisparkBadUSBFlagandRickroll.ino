#include <DigiKeyboard.h>

#define LED_PIN 1

void setup() {
  pinMode(LED_PIN, OUTPUT);

  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);


  DigiKeyboard.sendKeyStroke(KEY_T, MOD_CONTROL_LEFT | MOD_ALT_LEFT);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print("printf \"");
  DigiKeyboard.print("**********************************************\\n");
  DigiKeyboard.print("*                                            *\\n");
  DigiKeyboard.print("*     A R T E F A C T   W A S   H E R E !   *\\n");
  DigiKeyboard.print("*                                            *\\n");
  DigiKeyboard.print("**********************************************\\n");
  DigiKeyboard.print("\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(500);

 
  DigiKeyboard.print("xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(800);
    digitalWrite(LED_PIN, LOW);
    delay(800);
  
}
