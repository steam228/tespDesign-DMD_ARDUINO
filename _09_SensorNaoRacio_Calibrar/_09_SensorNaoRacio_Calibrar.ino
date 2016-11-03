//TESP DMD - Computaçao Física
// Ligação Thermistor 10K
// retirado de:
//http://playground.arduino.cc/ComponentLib/Thermistor2
// (Ground) ---- (10k-Resistor) -------|------- (Thermistor) ---- (+5v)
//                                     |
//                                Analog Pin 0

#include <math.h>

#define portaTherm A0

int valorTherm = 0;
int Temperatura = 0;

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
//         =log(10000.0/(1024.0/RawADC-1)) // for pull-up configuration
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius
 //Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
 return Temp;
}


void setup() {
 Serial.begin(9600);
}

void loop() {

valorTherm = analogRead(portaTherm);
Temperatura = Thermistor(valorTherm);

Serial.print("Temperatura: ");
Serial.print(Temperatura);
Serial.println(" celsius");

delay(20);


}





