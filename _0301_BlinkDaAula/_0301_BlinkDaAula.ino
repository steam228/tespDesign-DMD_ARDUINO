//Aula n3 Digital Input


#define luzita1 10  //O que é a mesma coisa que:
//int luzitaVerde = 10;
#define luzita2 9
#define luzita3 8
#define luzita4 7



int inter = 300;



void setup() {

  Serial.begin(9600);
  
  pinMode(luzita1, OUTPUT);
  pinMode(luzita2, OUTPUT);
  pinMode(luzita3, OUTPUT);
  pinMode(luzita4, OUTPUT);

  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, LOW);



}

void loop() {

  

  if (inter >= 0){

  for (int i = 0; i<=300 ; i=i+10){
  
  digitalWrite(luzita1, HIGH);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, LOW);
  delay(i);
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, HIGH);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, LOW);
  delay(i);
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, HIGH);
  digitalWrite(luzita4, LOW);
  delay(i);
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, HIGH);
  delay(i);
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, LOW);
  delay(i);
  inter = i;
  Serial.print ("tempo entre leds: ");
    Serial.println (i);


  }
  }

  if (inter <=500){
  for (int j = 500; j>=500 ; j=j-10){
  
  digitalWrite(luzita1, HIGH);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, LOW);
  delay(j);
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, HIGH);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, LOW);
  delay(j);
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, HIGH);
  digitalWrite(luzita4, LOW);
  delay(j);
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, HIGH);
  delay(j);
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, LOW);
  delay(j);
  
  Serial.print ("tempo entre leds: ");
    Serial.println (j);
inter = j;

  }
  }
 
    }
  
