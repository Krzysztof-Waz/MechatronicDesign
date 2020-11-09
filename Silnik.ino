void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
}

int counter = 0;
bool running = false;
bool CLKwise = false;
bool counterCLKwise = false;
int sw1 = LOW;
int sw2 = LOW;
int sw3 = LOW;
  
void loop()
{
  
  sw1 = digitalRead(2);
  sw2 = digitalRead(3);
  sw3 = digitalRead(4);
  //digitalWrite(7, HIGH);
  
  if(sw1 == HIGH) {
    delay(500);
    running = !running;
    
    if(running == true){
      	counter += 1;
      	Serial.print("Liczba uruchomien: ");
    	Serial.print(counter);
    	Serial.print("\n");
      	
    }else Serial.print("WYLACZONO\n");
  }
  
  if(sw2 == HIGH){
    delay(100);
   	Serial.print("ZGODNIE z ruchem wsk. zegara\n");
    CLKwise = false;
	counterCLKwise = true;
  }
   
   if(sw3 == HIGH){
    delay(100);
    Serial.print("PRZECIWNIE do ruchu wsk. zegara\n");
    CLKwise = true;
   	counterCLKwise = false;    
  }
  
  if(running){
      if(CLKwise)
      		digitalWrite(6, HIGH);
      
      else if(counterCLKwise)
      		digitalWrite(6, LOW);
      
      digitalWrite(7, HIGH);
    
  }
  else {
    digitalWrite(7, LOW);
  	CLKwise = false;
    counterCLKwise = false;
  }
  delay(20);
  
}