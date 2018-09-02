// ----------------------------
// Read value of connected LDR
// ----------------------------

// declaring variables and pin associations
int led = D0;
int ldr = A0;
int power = A5;
int analogvalue;    // used to store value of the LDR

void setup() {
    // setup pin direction
    pinMode(led, OUTPUT);
    pinMode(ldr, INPUT);
    pinMode(power, OUTPUT);
    
    // initial setup conditions
    digitalWrite(power, HIGH);
    digitalWrite(led, LOW);
    
    // Declaring Particle functions needed for the project
    Particle.variable("analogvalue", &analogvalue, INT);
    /* When the cloud is asked for "analogvalue", it will reference the variable
     * analogvalue in the app, which is an interger value
     */
    
    Particle.function("led", ledToggle);
    /* When the cloud is asked for the function "led",
     * it will employ the function ledToggle() from the app
     */ 
}

void loop() {
    // check the value of the LDR every 100ms, and store it in the variable analogvalue
    analogvalue = analogRead(ldr);
    delay(100);
}

// ledToggle() function used for this app
int ledToggle(String command) {
    if(command == "on") {
        digitalWrite(led, HIGH);
        return 1;
    }
    else if(command == "off") {
        digitalWrite(led, LOW);
        return 0;
    }
    else {
        return -1;
    }
}
