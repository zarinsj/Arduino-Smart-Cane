int pingTime_1;
int distance_1;
int pingTime_2;
int distance_2;
#define trigPin_1 4 // define TrigPin
#define echoPin_1 5 // define EchoPin.
#define trigPin_2 10
#define echoPin_2 11
#define Buzz_1 6 // Buzzer 

int test_setting_value = 2;
int delay_s1_on = 0;
int delay_s1_off = 0;

int delay_s2_on = 0;
int delay_s2_off = 0;


void setup() {
 pinMode(trigPin_1,OUTPUT);// set trigPin to output mode
 pinMode(echoPin_1,INPUT); // set echoPin to input mode
 pinMode(trigPin_2,OUTPUT);// set trigPin to output mode
 pinMode(echoPin_2,INPUT); // set echoPin to input mode
 pinMode(Buzz_1, OUTPUT);
 Serial.begin(9600); // Open serial monitor at 9600 band to see ping results.

 if (test_setting_value == 1)
{
  delay_s1_on = 100;
  delay_s1_off = 50;
  delay_s2_on = 500;
  delay_s2_off = 50;
}
else if (test_setting_value == 2)
{
  delay_s1_on = 200;
  delay_s1_off = 50;
  delay_s2_on = 1000;
  delay_s2_off = 20;
}
}
void loop() {
// Ultra sonic sensor 1
 // Clears the trigPin 
 digitalWrite(trigPin_1, LOW);
 delayMicroseconds(2);
 // Sets the trigPin on High state for 10 micro seconds so that it can emit a signal
 digitalWrite(trigPin_1, HIGH);
 delayMicroseconds(10);
 // Turn off the ultra sound
 digitalWrite(trigPin_1, LOW);
 // Reads the echoPin, returns the sound wave travel time in microseconds 
 pingTime_1 = pulseIn(echoPin_1, HIGH);
 // Calculating the distance
 distance_1 = pingTime_1*0.034/2;

 // Ultra sonic sensor 2
 // Clears the trigPin 
 digitalWrite(trigPin_2, LOW);
 delayMicroseconds(2);
 // Sets the trigPin on High state for 10 micro seconds so that it can emit a signal
 digitalWrite(trigPin_2, HIGH);
 delayMicroseconds(10);
 // Turn off the ultra sound
 digitalWrite(trigPin_2, LOW);
 // Reads the echoPin, returns the sound wave travel time in microseconds 
 pingTime_2 = pulseIn(echoPin_2, HIGH);
 // Calculating the distance
 distance_2 = pingTime_2*0.034/2;
 
 if(distance_2 < 30 && distance_2 > 20)
 {
    if (distance_1 < 30 && distance_1 > 15)
    {
      Serial.println("2 weak and 1 far");
      analogWrite(Buzz_1, 80);
      delay(1300);
      analogWrite(Buzz_1,255);
      delay(200);
      return;
    }
    if (distance_1 < 14.9 && distance_1 > 2)
    {
      Serial.println("2 weak and 1 close"); 
      analogWrite(Buzz_1, 80);
      delay(800);
      analogWrite(Buzz_1, 255);
      delay(200);
      return;   
    }
    Serial.println("2 weak only");
    analogWrite(Buzz_1, 80);
 }
 if(distance_2 < 19.9 && distance_2 > 10)
 {
    if (distance_1 < 30 && distance_1 > 15)
    {
      Serial.println("2 medium and 1 far");
      analogWrite(Buzz_1, 128);
      delay(500);
      analogWrite(Buzz_1,255);
      delay(500);
      return;
    }
    else if (distance_1 < 14.9 && distance_1 > 2)
    {
      Serial.println("2 medium and 1 close"); 
      analogWrite(Buzz_1, 128);
      delay(100);
      analogWrite(Buzz_1, 255); 
      delay(100);
      return;    
    }
    Serial.println("2 medium only");
    analogWrite(Buzz_1, 128);
 }
 if(distance_2 < 9.9 && distance_2 > 2)
 {
    if (distance_1 < 30 && distance_1 > 15)
    {
      Serial.println("2 strong and 1 far");
      analogWrite(Buzz_1, 192);
      delay(500);
      analogWrite(Buzz_1,255);
      delay(500);
      return;
    }
    if (distance_1 < 14.9 && distance_1 > 2)
    {
      Serial.println("2 strong and 1 close"); 
      analogWrite(Buzz_1, 192);
      delay(100);
      analogWrite(Buzz_1, 255); 
      delay(100); 
      return;  
    }
    Serial.println("2 strong only");
    analogWrite(Buzz_1, 192);
 }
 if(distance_2 > 30 || distance_2 < 2)
 {
  if(distance_1 < 30 && distance_1 > 15)
    {
      Serial.println("1 far");
      analogWrite(Buzz_1, 128);
      delay(500);
      analogWrite(Buzz_1,255);
      delay(500);
      return;
    }
  else if(distance_1 < 14.9 && distance_1 > 2)
    {
      Serial.println("1 close"); 
      analogWrite(Buzz_1, 128);
      delay(100);
      analogWrite(Buzz_1, 255);
      delay(100);
      return;
    }
    Serial.println("Neither");
    analogWrite(Buzz_1, 0);
    
    delay(1000);
 }

  
 // delay(100); // Wait 100ms between pings (about 20 pings/sec). 29ms should be the 
}
