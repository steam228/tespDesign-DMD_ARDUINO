//TESP Design para Media Digitais
//Computação Física
//Anotado em Português
//por André Rocha

//Digital Inpout + alteração de estado

#define botao 7 //botao na porta digital 7
#define led 10  //led na porta digital 10
//(ver ficheiro de fritzing)

boolean estadoDoBotao; //definicao de uma boleana de estado
boolean estadoAnteriorDoBotao; //guarda estado anterior

boolean estadoDoLed;


void setup() {

pinMode (botao, INPUT);
pinMode (led, OUTPUT); //é uma porta de entrada!

digitalWrite(led,LOW); //estado real e inicial do led 

estadoDoLed = false; //É mais facil e modluar usar uma boleana para ditar
//o estado do led... embora pareça redundante.



}

void loop() {

estadoDoBotao = digitalRead(botao); // a cada volta do código escreve o estado

// abaixo definimos uma condição em função do estado da variável
//(isto pode ser muito mais simples.... vejam o exemplo redux
// No entanto esta organização logica permite evoluir ao modularizar.

if (estadoDoBotao == true && estadoAnteriorDoBotao == false){
  
  estadoDoLed = !estadoDoLed; //isto quer dizer que a variavel assume o contrario do que estava antes
  
  }

digitalWrite(led,estadoDoLed);

estadoAnteriorDoBotao = estadoDoBotao; //grava-se para ver se se altera na próxima vez que for lido o botao.
//por comparação "saberemos" o que está a aocntecer... ou seja a distinguir o dedo que ficou colado no botão
// do dedo que carregou e saiu.
delay(2);



}
