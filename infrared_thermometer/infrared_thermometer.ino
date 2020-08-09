
/************************
  Arduino IR thermal gun
 ************************
  Developed by:
  PARIKALPANA NEPAL
  Damak, Nepal
  (c)2020
 ************************
*/

//----include necessary libraries--------
//IR sensor library
#include <Adafruit_MLX90614.h>

//I2C library
#include <Wire.h>

//OLED library
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

//----------------------------------------

//----------define constants---------------
#define MIN_DISTANCE 30     //minimum distance from person (in cm)
#define MAX_DISTANCE 40     //maximum distance from person (in cm)
#define TEMP_OFFSET 8.52    // temperature offset due to range
#define THRESHOLD_TEMP 100.4 //threshold temperature(in deg F) for warning alert
#define ECHO_PIN 2
#define TRIG_PIN 3
#define BUZZER_PIN 4
#define OLED_ADDRESS 0x3c //I2C address for OLED display
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

//-----------------------------------------

//----------initialize objects-------------

Adafruit_MLX90614 ir_sensor = Adafruit_MLX90614();             // initialize ir sensor object
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); //initialize OLED display
//-----------------------------------------

//setup
void setup()
{
  pinMode(TRIG_PIN, OUTPUT);                      //setup trigger pin
  pinMode(ECHO_PIN, INPUT);                       //setup echo pin
  ir_sensor.begin();                              //setup ir sensor
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS); //setup OLED display
  oled.setTextColor(WHITE);                       //set text color

  //display startup text
  oled.setTextSize(1);
  oled.setCursor(0, 0);
  oled.print("Infrared Thermometer");
  oled.setCursor(0, 10);
  oled.print("---------------------");
  oled.setCursor(0, 40);
  oled.print("Developed by:");
  oled.setCursor(0, 50);
  oled.print("Parikalpana Nepal");
  oled.display();

  delay(2000);
}

//code that run in loop
void loop()
{
  float temp = ir_sensor.readObjectTempF();
  float distance = getDistance();

  if (distance >= MIN_DISTANCE && distance <= MAX_DISTANCE)
  {
    //clear display
    oled.clearDisplay();

    //display temperature
    oled.setCursor(0, 0);
    oled.setTextSize(1);
    oled.print("Temperature:");
    oled.setCursor(0, 10);
    oled.setTextSize(3);
    oled.print(temp);
    oled.setTextSize(1);
    oled.cp437(true);
    oled.write(167);
    oled.setTextSize(2);
    oled.print("F");

    if (temp >= THRESHOLD_TEMP) {
      //display alert
      oled.setCursor(40, 40);
      oled.setTextSize(1);
      oled.print("alert!");

      warningTone(); //play warning tone
    }
    else {
      //display normal text
      oled.setCursor(40, 40);
      oled.setTextSize(1);
      oled.print("normal");

      readyTone();  //play ready tone
    }

    //finally display in oled using above configs
    oled.display();
  }
  else {
    //clear display
    oled.clearDisplay();

    //display idle text
    oled.setTextSize(1);
    oled.setCursor(0, 0);
    oled.print("Infrared Thermometer");
    oled.setCursor(0, 10);
    oled.print("---------------------");
    oled.setCursor(20, 30);
    oled.print("status: Idle!");
    oled.display();
  }

  //loop every half sec
  delay(500);
}

//play ready tone
void readyTone()
{
  tone(BUZZER_PIN, 250); // Send sound signal...
  delay(200);
  noTone(BUZZER_PIN);    // Stop sound...
  delay(200);
}

//play warning tone
void warningTone()
{
  //play warning tone in a loop
  for (int i = 0; i <= 3; i++) {
    tone(BUZZER_PIN, 880); // Send sound signal...
    delay(100);
    noTone(BUZZER_PIN);    // Stop sound...
    delay(100);
  }
}

//get distance in centimetres
float getDistance()
{
  digitalWrite(TRIG_PIN, LOW); //clears the trigger pin
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH); //sets the trigger pin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  float duration = pulseIn(ECHO_PIN, HIGH); //reads the echo pin, returns the sound wave travel time in microseconds
  return duration * 0.034 / 2;              //calculate and return distance in centimetres
}
