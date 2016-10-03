//Aula n3 Digital Input


#define luzitaVerde 10  //O que é a mesma coisa que:
//int luzitaVerde = 10;

void setup() {

pinMode(luzitaVerde, OUTPUT);

digitalWrite(luzitaVerde, LOW);



}

void loop() {

  digitalWrite(luzitaVerde, HIGH);
  delay(1000);
  digitalWrite(luzitaVerde, LOW);
  delay(1000);

  

}
