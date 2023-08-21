# Serial-Port-Reader-with-Python
This is a project that read a serial port with python and stores the data in a .csv file.
In this project, an Arduino with an Ultrassound HC-SR04 module and a DHT22 Temperature and Humidty Module are sending the data to the serial port.

The file Arduino_Ultrassound.ino sets the Arduino to read the distance of a plane object using an Ultrassound sensor that works clocking the travel time of an ultrassonic ping.
The Temperature and Humidity sensor are used to read the necessary data to calculate the speed of sound in the air.

The file Serial_port_reader_and_recorder.py reads the data that the Arudino is sending to the serial port and stores it in a .csv file.
In this python file, you insert the name that you want for your .csv and the duration of the measurements.
