void setup()
{
  Serial.begin(9600);
}

bool ask_for_expr = true;
bool expr_rcvd = false;
int charsRead;
char expr[100];

int a = 0, b = 0, i, op_sign;

void loop()
{
  if(ask_for_expr){
    Serial.print("Podaj cale wyrazenie\n");
    ask_for_expr = false;
  }
  
//Odczt ciągu znaków z terminala
 while (Serial.available()) {
    charsRead = Serial.readBytesUntil('\n', expr, sizeof(expr) - 1);  
    expr[charsRead] = NULL;
    Serial.print(expr);
   	Serial.print("\n");
   	expr_rcvd = true;
  }
  
  if(expr_rcvd){
    a = 0;
    b = 0;
    i = 0;
    //konwersja cyfr na int
    while(isDigit(expr[i])){
      a *= 10;
      a += (expr[i] - '0');
      i++;
    }
    op_sign = i;
    i++;
    while(isDigit(expr[i])){
      b *= 10;
      b += (expr[i] - '0');
      i++;
    }
    //
    switch(expr[op_sign]){
      case '/':
    	Serial.print("Wynik: ");
    	Serial.print(a/b);
    	Serial.print("\n");
    	expr_rcvd = false;
    	break;
      case '*':
    	Serial.print("Wynik: ");
    	Serial.print(a*b);
    	Serial.print("\n");
    	expr_rcvd = false;
    	break;
      case '+':
    	Serial.print("Wynik: ");
    	Serial.print(a+b);
    	Serial.print("\n");
    	expr_rcvd = false;
    	break;
      case '-':
    	Serial.print("Wynik: ");
    	Serial.print(a-b);
    	Serial.print("\n");
    	expr_rcvd = false;
    	break;
    }
    
    ask_for_expr = true;
    
  }
}