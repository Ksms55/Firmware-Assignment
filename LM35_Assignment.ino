#include<TimerOne.h>
int sensor_pin=A0; //LM35 temperature sensor connected to analog pin A0

void setup()
{
  pinMode(LED_BUILTIN,OUTPUT);
  Timer1.initialize(500000); //Initialize Timer1 with 500ms interval
  Timer1.attachInterrupt(blink_led); //Attach blink_led function to Timer1
}

void loop()
{
  //This function is empty because we're using TimerOne for timing
}

void blink_led()
{
  int temp = analogRead(sensor_pin); //Read temperature for LM35 sensor
  float temperatureC = (temp*5.0)/1024.0*100.0; //Converting temp into Celcius
  Serial.print("Temperature ");
  Serial.print(temperatureC);
  Serial.print(" in C");
   if(temperatureC<30) //Check temperature and control LED blinking interval
  {
    //Blink the LED every 250ms if temperature is less then 30 
    digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN)); //Toggle the LED state
    Timer1.initialize(250000); //Change Timer1 interval to 250ms
  }
  else
  {
    //Blink the LED every 500ms if temperature is greater then 30 
    digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN)); //Toggle the LED state
    Timer1.initialize(500000); ////Change Timer1 interval back to 250ms
  }
}


