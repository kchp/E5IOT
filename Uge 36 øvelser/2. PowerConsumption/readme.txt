Power consumption measuring
This small program is used for measuring the power consumption of the Photon in 3 different modes
Normal mode, sleep_mode and sleep_mode_deep

Everything will be running in the loop, with 10s for each mode.

Normal mode:
LED connected on D0 will turn on/off
LDR connected on A0 will see LED on and publish the event
Wi-Fi is enabled in this mode

Sleep mode:
same as normal mode, but Wi-Fi is off during sleep mode so nothing will be published

Deep sleep mode:
The whole device is put into deep sleep, so no app will be running for the duration

The 10s running time for each mode should give enough time to measure the power consumption
