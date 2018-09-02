// ----------------
// Motion detector
// ----------------
/**
 * The code uses an LED and LDR that are facing each other
 * when the light beam is broken the program detects this and gives notification
 */

// Declaring variables and associations
int led = D0;
int onLed = D7;
int ldr = A0;
int pwr = A5;

int intactValue;    // Average value read when beam is intact
int brokenValue;    // Average value read when beam is broken
int beamThreshold;  // Halfway value between the ledOnValue and ledOffValue
                    // above/below this value LED is assumed on/off

bool beamBroken = false;    // flag used to indicate new status or not

void setup() {
    // setup pin direction
    pinMode(led, OUTPUT);
    pinMode(onLed, OUTPUT);
    pinMode(ldr, INPUT);
    pinMode(pwr, OUTPUT);
    
    // initial startup conditions
    digitalWrite(pwr, HIGH);
    
    // initial calibration of the system
    // D7 LED will go on to indicate user to break the beam
    digitalWrite(onLed, HIGH);
    delay(2000);
    
    // D7 LED will go off and the LED will turn on
    digitalWrite(onLed, LOW);
    digitalWrite(led, HIGH);
    delay(500);
    
    // time to read the LDR
    int on_1 = analogRead(ldr); // read the LDR
    delay(200);                 // wait 200ms
    int on_2 = analogRead(ldr); // read the LDR
    delay(300);                 // wait 300ms
    
    // flash the D7 LED to indicate reading completed
    digitalWrite(onLed, HIGH);
    delay(100);
    digitalWrite(onLed, LOW);
    delay(100);
    digitalWrite(onLed, HIGH);
    delay(100);
    digitalWrite(onLed, LOW);
    delay(100);
    
    // D7 LED will go on to indicate user to unbreak beam
    digitalWrite(onLed, HIGH);
    delay(2000);
    
    // D7 LED will go off
    digitalWrite(onLed, LOW);
    
    // read the LDR again
    int off_1 = analogRead(ldr); // read the LDR
    delay(200);                  // wait 200ms
    int off_2 = analogRead(ldr); // read the LDR
    delay(1000);                 // wait 1000ms
    
    // flash the D7 LED 3 times to indicate reading completed
    digitalWrite(onLed, HIGH);
    delay(100);
    digitalWrite(onLed, LOW);
    delay(100);
    digitalWrite(onLed, HIGH);
    delay(100);
    digitalWrite(onLed, LOW);
    delay(100);
    digitalWrite(onLed, HIGH);
    delay(100);
    digitalWrite(onLed, LOW);
    delay(100);
    
    // the average and threshold values can now be calculated
    intactValue = (on_1+on_2)/2;
    brokenValue = (off_1+off_2)/2;
    beamThreshold = (intactValue+brokenValue)/2;

}

void loop() {
    /**
     * The loop function will be checking to see if the beam has been broken
     * When this happens a Particle.publich() will be sent to the cloud
     * so other devices will be able to check when the LED is on/off
     * D7 LED will also turn on when this happens
     */

    if(analogRead(ldr) > beamThreshold) {
        /**
         * If above threshold it is assumed the beam is intact.
         * If the beam was already intact no change is needed,
         * the beamBroken flag will be used to determine this
         */
        if(beamBroken == true) {
            /**
             * if the beam was broken before, the system has a new status
             * and a Particle.publish() will be sent to the cloud and D7 turned on
             */
            
            // send publish to the cloud
            Particle.publish("beamStatus","intact",60,PRIVATE);
            // flash D7 LED on and off
            digitalWrite(onLed, HIGH);
            delay(500);
            digitalWrite(onLed, LOW);
            
            // Set the flag to reflect current status
            beamBroken = false;
        }
        else {
            // No new status, nothing needs to be changed
        }
    }
    else {
        /**
         * If value is below the threshold, the beam is considered broken
         */
        if(beamBroken == false) {
            // send publish to the cloud
            Particle.publish("beamStatus","broken",60,PRIVATE);
            // flash D7 LED on and off
            digitalWrite(onLed, HIGH);
            delay(500);
            digitalWrite(onLed, LOW);
            
            // Set the flag to reflect current status
            beamBroken = true;
        }
        else {
            // No new status, nothing needs to be changed
        }
    }
}
