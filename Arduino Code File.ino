/* Smartphone Alarm via Bluetooth with Arduino */


int AnalogInput = 5;    // select the analog input pin 
int SensorValue = 0;    // variable to store the value coming from the sensor
int buzzer=11;           // Output pin for the buzzer
int ledOn = 9;          // define pin 9 of the arduino
int ledAlarm = 10;      // define pin 10 of the arduino
int Alarma = 500;
String readString;



void setup() {
  Serial.begin(9600);         // intialize communication at 9600 bps
  digitalWrite(buzzer,LOW);   // define buzzer as a digital output
  pinMode(ledOn,OUTPUT);
  pinMode(ledAlarm,OUTPUT);
  
}

void loop() {
  
  // NOW WE CHECK IF OUR BLUETOOTH MODULE IS ON OR OFF
  while(Serial.available()){
    delay(3);
    char text = Serial.read();
    readString += text;
  }
  if(readString.length() > 0){
    Serial.println(readString);
    if(readString == "1")          // 1 as "on"
    {
      digitalWrite(ledOn, HIGH);
    }
    if(readString == "0")          // 0 as "off"
    {
      digitalWrite(ledOn, LOW);
    }
    readString = "";
  }
  
  SensorValue = analogRead(AnalogInput);    // read the value from the sensor
  analogWrite(AnalogInput,SensorValue);   
  Serial.print(" ");
  Serial.println(SensorValue);  // show the value in Monitor Serial and Smartphone
  
  delay(500);
     
  
  if(SensorValue >= Alarma){     // if the SensorValue is higher than ALARMA
  
    digitalWrite(ledAlarm, HIGH);
    tone(buzzer,600,3000);
  }
  
  else 
    digitalWrite(ledAlarm, LOW);
    
}
