// Exercicio 1 Diagnóstico
// 

//baseado em:
//AnalogReadSerial - Arduino
//
//
//
// Para TESP DMD 
// UC Computação Física
// docente: André Rocha

// PORTAS //

#define ledAmarelo 10
#define ledVerde 9
#define ledVermelho 8
#define macaneta A0 //fio tijolo / porta A0
#define botao 7


// VARIAVEIS //

int rotacao = 0;
int rotAnt = 0;

/////// estados da maçaneta da porta

boolean zerou = false;
boolean rodou = false;
boolean prevRodaMac = false;

/////// estados do botao, ou seja, da passagem no corredor.

boolean estadoDoBotao; //definicao de uma boleana de estado
boolean estadoAnteriorDoBotao;

/// TIPO DE ACÇÃO

boolean porta = false;
boolean corredor = false;

// CONSTANTES //

const int macAbre = 180;

//contador de pessoas
int counter = 0;
boolean lock = false;


void setup() {

  Serial.begin(9600);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode (botao, INPUT);

  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);


}

void loop() {

  estadoDoBotao = digitalRead(botao);
  rotacao = analogRead(macaneta);
  rotacao = map(rotacao, 0, 1023, 0, 300);


  // Acções Relacionadas com entradas ou saídas - 1ª fase do exercício de Diagnóstico


  //Analisa o estado corrente da maçaneta face ao anterior (foi completa a acção?)
  if (rodaMac() == true && prevRodaMac == false) {
    //Serial.println("rodou"); //descomentar para debug
    porta = true; //// MUITO IMPORTANTE!! GRAVA PORTA ABERTA!!!!!
    //se se verificar que já rodou, foi depois de se ter passado no corredor ou seja, pisado o botão? 
    //se foi então houve uma saída caso contrário foi só alguém que espreitou e não completou a sequencia que implica entrar na sala.
    //se entrou decrementa-se o contador!
    if (corredor) {
      //Serial.println("saiu"); //descomentar para debug
      counter--;
      // como se verifica a acção completa podem agora ser zeradas as boleanas que nos permitem gravar as acções para comparação futura
      porta = false;
      corredor = false;

      // não pode haver pessoas negativas na sala (na prática nunca haveria) mas caso seja necessário para outra utilização
      //teriamos que dizer que caso haja por alguma razão um número inferior a zero, esse só pode ser zero.
      if (counter < 0)
      {
        counter = 0;
      }
      
      Serial.println(counter);
    }
  }

  
  //Analisa o estado corrente da maçaneta face ao anterior (foi completa a acção?)
  if (estadoDoBotao == true && estadoAnteriorDoBotao == false) {
    //Serial.println("carregou"); //descomentar para debug
    corredor = true; //// MUITO IMPORTANTE!! GRAVA PASSAGEM NO CORREDOR!!!
    // O mesmo de acima, se a porta já tinha sido aberta quer dizer que é a segunda acção logo completa a sequencia de entrar!
    
    if (porta == true && lock == false) {
      //Serial.println("entrou"); //descomentar para debug
      counter++;
      // como se verifica a acção completa podem agora ser zeradas as boleanas que nos permitem gravar as acções para comparação futura
      porta = false;
      corredor = false;
      Serial.println(counter);
    }
  }


  //Decisões com base no contador (ligar e desligar leds, trancar ou não sistema)
  
  if (counter == 0){
    digitalWrite(ledVerde,HIGH);
    digitalWrite(ledAmarelo,LOW);
    digitalWrite(ledVermelho,LOW);
    lock = false;
    
    }

  if (counter > 0 && counter < 10){
    digitalWrite(ledAmarelo,HIGH);
    digitalWrite(ledVerde,HIGH);
    digitalWrite(ledVermelho,LOW);
    lock = false;
  }

   if (counter >=10){
    
    digitalWrite(ledAmarelo,HIGH);
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledVermelho,HIGH);
    lock = true;
    }
  
  
  
  estadoAnteriorDoBotao = estadoDoBotao;
  prevRodaMac = rodaMac();
  delay(4);


}



// Função para detectar sequencia de rotação na Maçanetal

boolean rodaMac () {

    if (rotacao >= 180 && zerou == true && rodou == false) {
      rodou = true;
      return false;
    }
    if (rotacao == 00 && zerou == true && rodou == true) {
      rodou = false;
      zerou = false;
      return true;
      
    }
    
    rotAnt = rotacao;
}

