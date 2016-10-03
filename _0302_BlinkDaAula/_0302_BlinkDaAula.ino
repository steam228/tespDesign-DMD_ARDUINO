//Aula n3 Digital Input


#define luzita1 10  //O que é a mesma coisa que:
//int luzitaVerde = 10;
#define luzita2 9
#define luzita3 8
#define luzita4 7



int inter = 80;



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






  digitalWrite(luzita1, HIGH);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, LOW);
  delay(random(inter));
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, HIGH);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, LOW);
  delay(random(inter));
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, HIGH);
  digitalWrite(luzita4, LOW);
  delay(random(inter));
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, HIGH);
  delay(random(inter));
  digitalWrite(luzita1, LOW);
  digitalWrite(luzita2, LOW);
  digitalWrite(luzita3, LOW);
  digitalWrite(luzita4, LOW);
  delay(random(inter));




}
