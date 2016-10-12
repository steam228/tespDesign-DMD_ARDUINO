//TESP Design para Media Digitais
//Computação Física
//Anotado em Português
//por André Rocha

//Digital Inpout

//exemplo ultra reduzido

void setup() {
pinMode (7, INPUT);
pinMode (10, OUTPUT); 
}
void loop() {
digitalWrite(10,digitalRead(7));
delay(2);
}
