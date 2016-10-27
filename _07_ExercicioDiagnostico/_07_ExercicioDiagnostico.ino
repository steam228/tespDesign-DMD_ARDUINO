// Exercicio 1 Diagnóstico
// André Rocha

//baseado em:
//AnalogReadSerial - Arduino
//
//
//


// PORTAS //

int macaneta = A0; //fio tijolo / porta A0



// VARIAVEIS //

int rotacao = 0;



void setup() {

  Serial.begin(9600);


}

void loop() {

  rotacao = analogRead(macaneta);




  Serial.print ("Rotação da Maçaneta: ");
  Serial.println(rotacao);


}
