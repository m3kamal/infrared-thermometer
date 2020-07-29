# Infrared thermometer
This is a infrared thermometer also known as thermal gun used to measure body temperature of person standing in front of it. It uses ultrasonic sensor to detect if something is within the specified range(default min 30 cm and max 35 cm) and show the temperature otherwise show idle message. It also provides sound alert if temperature crosses specified threshold(currently 100.4 deg F). This device can be fully configured to work as per needed.The threshold distance, temperature and alert messages and alert tones can be customized easily.

## Components used

### 1. Arduino Nano 
<img src="https://store-cdn.arduino.cc/usa/catalog/product/cache/1/image/520x330/604a3538c15e081937dbfbd20aa60aad/A/0/A000005_featured_2.jpg" height="240" width="320">

### 2. OLED display 
<img src="https://cdn.shopify.com/s/files/1/0264/7629/products/DM-OLED096-636-show_grande.jpg?v=1573547128" height="240" width="320">

### 3. MLX90614 IR sensor 
<img src="https://components101.com/sites/default/files/component_pin/MLX90614-Pinout_2_0.jpg" height="240" width="320">

### 4. HC-SR04 Ultrasonic distance sensor
<img src="https://www.robotshop.com/media/catalog/product/cache/image/1350x/9df78eab33525d08d6e5fb8d27136e95/h/c/hc-sr04-ultra01-ultrasonic-range-finder-2.png" height="280" width="320">

### 5.  Passive Piezoelectric buzzer module(only buzzer without module shown in wiring diagram)
<img src="https://www.tdegypt.com/wp-content/uploads/2017/04/172363375298-0_600.jpg" height="240" width="320">

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
 
