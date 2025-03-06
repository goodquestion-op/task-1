#include <Servo.h>


const int Refresh = 50;


const int soundPin = A0;


const int In1 = 9;
const int In2 = 8;
const int EnA = 6;


const int Button = 11;
const int Buzz = 13;


const int trig = 3;
const int echo = 2;
const int LED = 4;
int var = 0;
int gri = 0;




const int ser = 12;
Servo myservo;


const int pot = A1;




unsigned long previousMillis = 0;
long interval = 1000;
int ledState = LOW;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


  pinMode(soundPin, INPUT);


  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(EnA, OUTPUT);


  pinMode(Buzz, OUTPUT);
  pinMode(Button, INPUT);


  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED, OUTPUT);


  myservo.attach(ser);


  pinMode(pot, INPUT);
}


void go(){
  int val = analogRead(soundPin);//will need to map this but don't right tuning
  val = constrain(val, 0, 1023);
  val = map(val, 0, 1023, 80, 255);


  analogWrite(EnA, val);


  digitalWrite(In1, HIGH);


  digitalWrite(In2, LOW);
 
  // Serial.println(val);
  // Serial.print("val ");
 // Serial.println(val*mod);
  //Serial.println("motor");
}
void buzz(){
  int beep = analogRead(pot);
  beep = map(beep, 0,1023, 800, 5000 );
  Serial.println(beep);
  if (digitalRead(Button) == HIGH){
    tone(Buzz, beep);
    Serial.println("buzz?");
  }else{
    noTone(Buzz);
  }


}
void ultra(){
  int dis = analogRead(pot);
    long duration, cm,distance;


   


    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(5);
    digitalWrite(trig, LOW);


    duration = pulseIn(echo, HIGH);


    cm = SoS(duration);
    distance = SoS(duration);
    var = cm;
    gri = distance;
    long delVal = map(cm, 5, 300, 20, 500);
    dis = map(dis, 0, 1023, 0,30 );
      // Serial.println(var);
      // Serial.print("cm ");
    long rig = map(distance, 5, 300, 50, 1000);


    if (cm < dis+30 ){      
      myservo.write(60);
    }else{
      myservo.write(0);
    }


    long interval = gri;
    unsigned long currentMillis = millis();
   
     if (currentMillis - previousMillis >= interval) {
       // save the last time you blinked the LED
      previousMillis = currentMillis;
        // if the LED is off turn it on and vice-versa:
        if (ledState == LOW) {
         ledState = HIGH;
        } else {
          ledState = LOW;
        }


        // set the LED with the ledState of the variable:
      digitalWrite(LED, ledState);
    }
 
}
void big_pot(){
  int vip = analogRead(pot);
  vip = map(vip, 0, 1023, 0,30 );
  //Serial.println(vip);
  // basically not needed just used for the serial when I first added


 
}








void loop() {
  // put your main code here, to run repeatedly:
 
  big_pot();
  ultra();
  go();
  buzz();


 
  delay(Refresh);
}






long SoS(long pulse){
  return pulse/ 29 /2;
}






 
   
}
void loop() {
  // put your main code here, to run repeatedly:
 
  big_pot();
  ultra();
  go();
  buzz();


 
  delay(Refresh);
}






long SoS(long pulse){
  return pulse/ 29 /2;
}
