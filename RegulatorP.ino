


int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
   

}

int setpoint = 10000;
float kp = 0.05;
int current_pos;
int error;
int control_signal;

void loop()
{
	
  	
  
  current_pos = readUltrasonicDistance(7,7);
  cm = 0.01723*current_pos;
  Serial.print(current_pos);
  Serial.print("--> w cm: ");
  Serial.print(cm);
  Serial.print("\n");
  
  error = setpoint - current_pos;
  control_signal = error*kp;
  if(control_signal < 0)
    	control_signal = -control_signal;
  if(control_signal > 255)
    	control_signal = 255;
  if(error > 0){
    	digitalWrite(2,HIGH);
    	digitalWrite(3,LOW);
  }
  else if(error < 0){
    	digitalWrite(3,HIGH);
    	digitalWrite(2,LOW);
  }
  analogWrite(5,control_signal);
  
  
}