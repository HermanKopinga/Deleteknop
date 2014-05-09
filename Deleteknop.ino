/* 
 
 Delete button source code by Herman Kopinga, herman@kopinga.nl.
 created april 2013.
 
 Easy as pie!
 Modify to suit your own need.
 
 Based directly on Keyboard Button test an Aruino code example 
 in the public domain originally by Tom Igoe.
 http://www.arduino.cc/en/Tutorial/KeyboardButton
 */

const int buttonPin = A0;             // input pin for pushbutton
boolean previousButtonState = HIGH;   // for checking the state of a pushButton

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed, and it's currently pressed:
  if ((buttonState != previousButtonState) && (buttonState == HIGH)) {
    // Keyboard.press(KEY_LEFT_GUI); // Optional: Command key on mac.
    // Keyboard.press(KEY_LEFT_SHIFT); // Optional: Any shift key
    Keyboard.press(KEY_DELETE);
    delay(10);
    Keyboard.releaseAll();	// send the button release
    delay(50);                  // poor man's debounce
  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState; 
}

