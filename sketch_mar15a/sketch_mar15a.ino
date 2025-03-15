#define motor1A 13
#define motor2A 12
#define motor1B 33
#define motor2B 32




// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);  
  pinMode(motor1B, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  // Rotate
  forward();
  delay(2000); 

  // Rotate in the opposite direction
  backward();
  delay(2000); 

  // Stop
  stop();
  delay(3000);
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

