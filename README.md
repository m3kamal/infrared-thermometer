# Infrared thermometer
This is a infrared thermometer also known as thermal gun used to measure body temperature of person standing in front of it. It uses ultrasonic sensor to detect if something is within the specified range(default min 30 cm and max 35 cm) and show the temperature otherwise show idle message. It also provides sound alert if temperature crosses specified threshold(currently 100.4 deg F). This device can be fully configured to work as per needed.The threshold distance, temperature and alert messages and alert tones can be customized easily.

## Components used
* Arduino Nano
* 0.96" OLED monochrome display
* MLX90614 IR sensor
* HC-SR04 Ultrasonic distance sensor
* Passive Piezoelectric buzzer module(only buzzer without module shown in diagram)

## Installation
 * Download this repo as zip and extract
 * Move libraries folder inside Arduino folder usually located in My Documents
 * Open infrared_thermometer folder and open ino file
 * compile and upload
 
## Wiring
![Wiring diagram](https://github.com/m3kamal/infrared-thermometer/blob/master/wiring_fritzing_bb.jpg)
 ### OLED display <--------> Arduino Nano
 * SDA ---------- A4
 * SCL ---------- A5
 * VCC ---------- 3.3V
 * GND ---------- GND
 
 ### MLX90614 IR sensor <--------> Arduino Nano
 * SDA ---------- A4
 * SCL ---------- A5
 * VCC ---------- 3.3V
 * GND ---------- GND
 
 ### HC-SR04 ultrasonic sensor <--------> Arduino Nano
 * ECHO ---------- D2
 * TRIG ---------- D3
 * VCC ---------- 3.3V
 * GND ---------- GND
 ### Piezo Buzzer <--------> Arduino Nano
 * I/O ---------- D4
 * VCC ---------- VIN
 * GND ---------- GND
 
