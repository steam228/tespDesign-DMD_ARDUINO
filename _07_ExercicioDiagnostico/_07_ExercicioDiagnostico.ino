// Exercicio 1 Diagnóstico
// André Rocha

//baseado em:
//AnalogReadSerial - Arduino
//
//
//


// PORTAS //

#define ledAmarelo 10
#define ledVerde 9
#define ledVermelho 8
#define macaneta A0 //fio tijolo / porta A0
#define botao 7


// VARIAVEIS //

int rotacao = 0;
int rotAnt = 0;

boolean activou = false;

boolean estadoDoBotao; //definicao de uma boleana de estado
boolean estadoAnteriorDoBotao;
boolean estBot = false;

boolean macState = false;
boolean macStateAnt = false;

boolean botaState = false;
boolean botaStateAnt = false;


// CONSTANTES //

const int macAbre = 180;


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




digitalWrite(ledAmarelo, rodaMac());
digitalWrite(ledVerde, carregaBotao());

delay(4);


}


boolean rodaMac () {

  
  rotacao = analogRead(macaneta);
  rotacao = map(rotacao, 0,1023,0,300);


  if (rotacao >= 180 && rotAnt <180){

      activou = true;
      return false;
      Serial.println("ACTIVOU");
     
       }
       

   if (rotacao == 0){
    if (activou ==true){
       return true;
       activou == false;
       Serial.println("ABRIU E DESACTIVOU");
      }

      
   else{
    
    return false;
    }
   
   }
   rotAnt = rotacao;
}

boolean carregaBotao() {

  estadoDoBotao = digitalRead(botao);

  if (estadoDoBotao == true && estadoAnteriorDoBotao == false){
  
  estBot = !estBot; 
  }

   return estBot;

  estadoAnteriorDoBotao = estadoDoBotao;
  
  }
