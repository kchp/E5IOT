//--------------
// Blink an LED
// -------------

int led1 = D0;
int led2 = D7;

void setup() {
    pinMode(led1, OUTPUT);  // Set pin direction to output
    pinMode(led2, OUTPUT);
}

void loop() {
    // Blink the LED
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    
    // Leave it on for number in parentheses ms
    delay(500);
    
    // Turn off LED
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    
    // Leave it off for number in parentheses ms
    delay(500);
}
