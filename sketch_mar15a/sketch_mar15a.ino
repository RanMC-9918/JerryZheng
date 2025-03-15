#define motor1A 13
#define motor2A 14
#define motor1B 33
#define motor2B 32


// PWM settings
const int freq = 500; // PWM frequency: 500 Hz
const int resolution = 8; // PWM resolution: 8 bits


void setup() {
  // Set up PWM
  ledcAttach(motor1A, freq, resolution);
  ledcAttach(motor2A, freq, resolution);

  Serial.begin(115200);
}

void loop() {
  // Increase speed gradually
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    Serial.println(dutyCycle);
    ledcWrite(motor1A, dutyCycle);
    ledcWrite(motor2A, 0);
    delay(50);
  }

  delay(2000);

  // Decrease speed gradually
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    Serial.println(dutyCycle);
    ledcWrite(motor1A, dutyCycle);
    ledcWrite(motor2A, 0);
    delay(50);
  }
  
  delay(2000);
}


void forward()
{
  digitalWrite(motor1A, HIGH);     
  digitalWrite(motor2A, LOW);   
  digitalWrite(motor1B, HIGH);     
  digitalWrite(motor2B, LOW);  
}

void backward()
{
  digitalWrite(motor1A, LOW);     
  digitalWrite(motor2A, HIGH);   
  digitalWrite(motor1B, LOW);     
  digitalWrite(motor2B, HIGH);  
}

void stop()
{
  digitalWrite(motor1A, LOW);     
  digitalWrite(motor2A, LOW);
  digitalWrite(motor1B, LOW);     
  digitalWrite(motor2B, LOW);    
}

