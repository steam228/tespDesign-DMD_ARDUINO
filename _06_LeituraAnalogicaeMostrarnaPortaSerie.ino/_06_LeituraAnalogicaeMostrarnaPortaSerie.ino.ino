
/// portas
#define portaDoSensor A0
#define led 10



//// variáveis
int valorDoSensor = 0;
int rotacao = 0;


/// constante
int rotacaoMax = 150;

void setup() {
  pinMode(led,OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  digitalWrite(led,LOW);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  valorDoSensor = analogRead(portaDoSensor);
  rotacao = map(valorDoSensor,0,1023,0,300);
  // print out the value you read:
  Serial.print("O Valor do Sensor é: ");
  Serial.println(valorDoSensor);
  Serial.print("mas, o valor da rotacao é : ");
  Serial.print(rotacao);
  Serial.println(" º");
  Serial.println("///////////////////////// ");

  if(rotacao >= rotacaoMax) {

    digitalWrite(led,HIGH);
    
    }

   else {
    digitalWrite(led,LOW);
    
    }
  
  delay(1);        // delay in between reads for stability
}
