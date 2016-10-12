//TESP Design para Media Digitais
//Computação Física
//Anotado em Português
//por André Rocha

//Digital Inpout

#define botao 7 //botao na porta digital 7
#define led 10  //led na porta digital 10
//(ver ficheiro de fritzing)

boolean estadoDoBotao; //definicao de uma boleana de estado



void setup() {

pinMode (botao, INPUT);
pinMode (led, OUTPUT); //é uma porta de entrada!

digitalWrite(led,LOW); //estado inicial do led


}

void loop() {

estadoDoBotao = digitalRead(botao); // a cada volta do código escreve o estado

// abaixo definimos uma condição em função do estado da variável
//(isto pode ser muito mais simples.... vejam o exemplo redux
// No entanto esta organização logica permite evoluir ao modularizar.

if (estadoDoBotao == true){
  
  digitalWrite(led,HIGH);
  
  }

else {

  digitalWrite(led,LOW);
  
  }

delay(2);



}
