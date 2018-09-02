Simple motion detector

- Build the system shown in Setup.png
	- bend the LED and LDR so they face each other

- Flash the Photon with the .bin

- Initial calibration
	- D7 LED will turn on for 2 sec at start signaling user to break beam
	- When it turns off the LED will turn on and readings will be taken
	- D7 LED will flash twice to indicate readings completed
	- D7 LED will turn on for 2 sec signaling user to reestablish the beam
	- When it turns off readings will be taken
	- D7 LED will flash twice to indicate readings completed

- When the beam is broken D7 LED will flash once and current status will be published to the cloud
  and the same will happen when the beam is reestablished

- Cloud interface not yet completed

