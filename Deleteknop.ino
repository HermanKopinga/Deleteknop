/* 
 
 Delete button source code by Herman Kopinga, herman@kopinga.nl.
 created april 2013.
 
 Easy as pie!
 Modify to suit your own need.
 
 Based directly on Keyboard Button test an Aruino code example 
 in the public domain originally by Tom Igoe.
 http://www.arduino.cc/en/Tutorial/KeyboardButton
 
 Added button debounce code of my own design, easy enough to understand?
   Reason for debounce is explained on (of course) Wikipedia:
   http://en.wikipedia.org/wiki/Switch#Contact_bounce
 */

const int buttonPin = A0;             // input pin for pushbutton
boolean previousButtonState = HIGH;   // for checking the state of a pushButton
unsigned long lastChange = 0;         // moment of last change to button state.
boolean actionRequired = false;       // by default, no action, only when the switch state changed.
                                      // not really needed, added for clarity. 

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);

  // if the button state has changed, save the moment this happened.
  if (buttonState != previousButtonState) {
    lastChange = millis();
    actionRequired = true;
  }
  
  // if the button currently pressed and there hasn't been a change in 10 milliseconds.
  if (buttonState == LOW && actionRequired && (millis() - lastChange) > 10) {
    // Keyboard.press(KEY_LEFT_GUI);   // optional: Windows or Command key
    // Keyboard.press(KEY_LEFT_SHIFT); // optional: Any shift key
    Keyboard.press(KEY_DELETE);        // press the key
    delay(10);                         // small delay, not always needed
    Keyboard.releaseAll();	       // release the key(s)
    actionRequired = false;            // action has run, make sure it won't run before next release.
  }
  
  // save the current button state for comparison next time:
  previousButtonState = buttonState; 
}

