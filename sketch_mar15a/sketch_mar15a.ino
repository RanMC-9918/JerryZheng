
#include <ESP32Servo.h>
// Define constants for the x and y axis and the button pins
#define xAxis 34
#define yAxis 35
#define btn 33
// Define the servo and the pin it is connected to
Servo myServo;
const int servoPin = 27;

// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500; // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

// Define pins for the ultrasonic sensor
const int echoPin = 25;
const int trigPin = 26;
// the setup function runs once when you press reset or power the board
void setup() {
  // Begin serial communication at 115200 baud rate
  Serial.begin(115200);
  // Set echoPin as input and trigPin as output
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  // Print sensor information to the serial monitor
  Serial.println("Ultrasonic sensor:");  
  // Attach the servo to the specified pin and set its pulse width range
  myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

  // Set the PWM frequency for the servo
  myServo.setPeriodHertz(50); // Standard 50Hz servo
  
  // Initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

  // Set the mode of the button pin to input
  pinMode(btn, INPUT);  
}


void loop() {
  // Rotate the servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    myServo.writeMicroseconds(pulseWidth);
    delay(15);
  }

  // Rotate the servo from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    myServo.writeMicroseconds(pulseWidth);
    delay(15);
  }
  float distance = readSensorData();
  // Print the measured distance to the serial monitor
  Serial.print(distance);   
  Serial.println(" cm");
  // Delay between readings
  delay(200);
  
  // Read the analog value for x,y axis
  int xValue = analogRead(xAxis);
  int yValue = analogRead(yAxis); 

  // Read the digital value from the button pin
  int btnValue = digitalRead(btn);
  
  // print out the values
  Serial.printf("Joystick value is %d , %d , %d \n",xValue,yValue,btnValue);
  
  delay(300);  // Delay between reads
}
float readSensorData() {
  // Trigger a low signal before sending a high signal
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Send a 10-microsecond high signal to the trigPin
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  // Return to low signal
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the high signal on the echoPin
  unsigned long microsecond = pulseIn(echoPin, HIGH);

  // Calculate the distance using the speed of sound (29.00µs per centimeter)
  float distance = microsecond / 29.00 / 2;

  // Return the calculated distance
  return distance;
}

