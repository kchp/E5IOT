Small program to turn an LED on/off or read the value of an LDR

- Open the .html in an editor and change the device ID and access token in the below line
<form action="https://api.particle.io/v1/devices/your-device-ID-goes-here/led?access_token=your-access-token-goes-here" method="POST">

- Flash the Photon with the .bin file
- Open the .html file in a browser for LED control or use the Particle CLI commandline calls
	- particle call <deviceID> led on
	- particle call <deviceID> led off

- To read the value of the LDR use this commandline call
	- particle variable get <deviceID> analogvalue
