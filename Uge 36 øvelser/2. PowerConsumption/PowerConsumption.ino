// ----------------------------
// Power consumption measuring
// ----------------------------

/**
 * This small program is used for measuring the power consumption of the Photon in 3 different modes
 * Normal mode, sleep_mode and sleep_mode_deep
 * 
 * In all 3 modes the program will be running the same routine, to ensure the only difference will be the different modes activated
 * In normal mode the wifi is active and publish functions will be sent, in sleep mode Wi-Fi is turned off so publish calls should not be sent
 * in deep sleep the whole device is put to sleep for the duration.
 */
 
 // Declaring variables and associations
 int led = D0;
 int onLed = D7;
 int ldr = A0;
 int pwr = A5;
 int rotation = 0;
 
 
void setup() {
    // setup pin direction
    pinMode(led, OUTPUT);
    pinMode(onLed, OUTPUT);
    pinMode(ldr, INPUT);
    pinMode(pwr, OUTPUT);
    
    // initial startup conditions
    digitalWrite(pwr, HIGH);
}

void loop() {
    while(rotation < 10) {
        digitalWrite(led,HIGH);
        Particle.publish("ledStatus","ON");
        delay(500);
        digitalWrite(led,LOW);
        Particle.publish("ledStatus","OFF");
        delay(500);
        rotation++;
    }
    rotation = 0;
    flash();
    System.sleep(10);
    while(rotation < 10) {
        digitalWrite(led,HIGH);
        Particle.publish("ledStatus","ON");
        delay(500);
        digitalWrite(led,LOW);
        Particle.publish("ledStatus","OFF");
        delay(500);
        rotation++;
    }
    rotation = 0;
    flash();
    System.sleep(SLEEP_MODE_DEEP,10);
}

void flash() {  // flash D7 LED 3 times
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
}