//TESP Design para Media Digitais
//Computação Física
//Anotado em Português
//por André Rocha

//Digital Output



//Nesta zona definimos variáveis, portas, carregamos bibliotecas.... 
//Aguardem por exemplos que utilizam esta área de modo mais amplo

#define luzitaVerde 10  //O que é a mesma coisa que:
//int luzitaVerde = 10; //Dá um nome à porta, logo ao objecto
// é sensivel às CAPS, tal como as varáveis, funções e tudo o resto.


//O setup é um código que só corre um ciclo.
//todos os passos preparatorios devem ser colocados aqui:

void setup() {


pinMode(luzitaVerde, OUTPUT); 
//Aqui define-se o tipo de utilização da porta
//Acaba por ser como definir se é 5V ou GND

digitalWrite(luzitaVerde, LOW);
//o setup corre só uma vez, por isso aqui determinamos de que forma arranca
//a porta no nosso programa. Neste caso queremos que desligada, ou seja,
// com o led apagado

}


// O loop não para, ciclo após ciclo repete sempre o código nele presente.
void loop() {

  //Escreve digitalmente na porta luzitaVerde qualquer coisa como ON, ou LIGA, ou verdadeiro, ou 1 ou voltagem máxima
  digitalWrite(luzitaVerde, HIGH);
  //Espera 1 segundo, mil milisegundos
  delay(1000);
  //Agora desliga, torna falso
  digitalWrite(luzitaVerde, LOW);
  //e espera outra vez neste estado, neste ponto do programa
  delay(1000);

  //como não há mais nenhuma linha de código aqui debaixo, volta a iniciar,
  // Assim se cria nasceu "A moda do pisca pisca"
 
}
