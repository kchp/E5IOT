// ----------------------------------
// Controling LEDs over the Internet
// ----------------------------------

int led1 = D0;
int led2 = D7;

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    
    // Declaring Particle.function for switching LED on/off from the cloud
    Particle.function("led",ledToggle);
    
    // Setting startup condition
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
}

void loop() {
    // Not needed in this example
}

/*** 
 * Particle.functions always take a string as an argument and return an integer
 * Since we can pass a string, it means that we can give the program commands on how the function should be used.
 * In this case, telling the function "on" will turn the LED on and "off" will turn the LED off.
 * Then, the function returns a value to us to let ud know what happened.
 * In this case, it will return 1 for the LED turning on, 0 for the LED turning off, and -1 if we received a
 * command that didn't do anything to the LED.
 */
int ledToggle(String command) {
    if(command == "on") {
        digitalWrite(led1, HIGH);
        // digitalWrite(led2, HIGH);
        return 1;
    }
    else if(command == "off") {
        digitalWrite(led1, LOW);
        // digitalWrite(led2, LOW);
        return 0;
    }
    else {
        return -1;
    }
}
