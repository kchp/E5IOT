// --------------------------------
// Motion detector
// Publish and Subscribe functions
// --------------------------------
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
    
    // Subscribing to a buddy's event using Particle.subscribe
    Particle.subscribe("buddy_event_name", myHandler);
    /**
     * Subscribe will listen for the event "buddy_event_name" and, when it finds it, will run the function myHandler()
     * "buddy_event_name" should be replaced with the actual unique event name from the buddy's Photon
     */
    
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
    int off_1 = analogRead(ldr); // read the LDR
    delay(200);                 // wait 200ms
    int off_2 = analogRead(ldr); // read the LDR
    delay(1000);                 // wait 300ms
    
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
    int on_1 = analogRead(ldr); // read the LDR
    delay(200);                  // wait 200ms
    int on_2 = analogRead(ldr); // read the LDR
    delay(300);                 // wait 1000ms
    
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
            Particle.publish("statusBadKitty","intact");
            /**
             * publish event and flash D7 LED on and off
             * this is a private publish that will only be visiable to my devices
             */
            //Particle.publish("beamStatus","broken",60,PRIVATE); 
            //digitalWrite(onLed, HIGH);
            //delay(500);
            //digitalWrite(onLed, LOW);
            
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
            Particle.publish("statusBadKitty","broken");
            //Particle.publish("beamStatus","broken",60,PRIVATE); 
            //digitalWrite(onLed, HIGH);
            //delay(500);
            //digitalWrite(onLed, LOW);
            
            // Set the flag to reflect current status
            beamBroken = true;
        }
        else {
            // No new status, nothing needs to be changed
        }
    }
}

void myHandler(const char *event, const char *data) {
    /**
     * Particle.subscribe handlers are void functions, which means they don't return anything.
     * They take 2 variables-- the name of the event, and any data that goes along with the event.
     * In this case, the event will be "buddy_event_name" and the data will be "intact" or "broken".
     * 
     * Since the input here is a char, we can't do
     *      data == "intact"
     *      or
     *      data == "broken"
     * chars don't work that way. Instead we're going to strcmp(), which compares 2 chars.
     * If they are the same, strcmp will return 0
     */
     
    if(strcmp(data,"intact") == 0) {
        // if buddy's beam is intact, then turn your board LED off
        digitalWrite(onLed, LOW);
    }
    else if (strcmp(data,"broken") == 0) {
        // if buddy's beam is broken, then turn your board LED on
        digitalWrite(onLed, HIGH);
    }
    else {
        // do nothing if something else is received
    }
}
