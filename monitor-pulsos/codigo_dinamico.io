#include <LiquidCrystal.h>

const int pht = 34;
const int nInter = 4;

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(14, 27, 26, 25, 33, 32);

float signFilt = 0;
float pBase = 0;

float aphSign = 0.15;
float aphBase = 0.01;

float offset = 0.8;

float lAnterior = 0;

float bpmFilt = 0;
float aphBPM = 0.35;

bool picoDet = false;

unsigned long ultLat = 0;
unsigned long ultBPMVal = 0;

int bpm = 0;

int tMuerto = 400;
int indice = 0;

unsigned long intervalos[nInter];

bool bufferLleno = false;


void mostrarBPM(int valor) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BPM: ");
  if(valor < 10) {
    lcd.print("  ");
  }
  else if(valor < 100) {
    lcd.print(" ");
  }
  lcd.print(valor);
  lcd.print(" BPM");
}


void mostrarSinDedo() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BPM: --");
  lcd.setCursor(0,1);
  lcd.print("No Finger");
}


void setup() {
  Serial.begin(115200);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Monitor BPM");
  delay(2000);
  lcd.clear();
  mostrarSinDedo();
  for(int i=0; i<nInter; i++) {
    intervalos[i] = 0;
  }
}


void loop() {
  long suma = 0;
  for(int i=0; i<10; i++) {
    suma += analogRead(pht);
    delay(2);
  }
  
  float lectura = suma / 10.0;
  signFilt = aphSign * lectura + (1 - aphSign) * signFilt;
  pBase = aphBase * signFilt + (1 - aphBase) * pBase;
  float senalAmplificada =(signFilt - pBase) * 5;
  float umbral = offset;

  if(senalAmplificada > umbral && lAnterior > senalAmplificada && !picoDet && millis() - ultLat > tMuerto) {
      picoDet = true;
      unsigned long tiempoActual = millis();
      unsigned long intervalo = tiempoActual - ultLat;

      if(intervalo > 300 && intervalo < 2000) {
        intervalos[indice] = intervalo;
        indice++;
        if(indice >= nInter) {
          indice = 0;
          bufferLleno = true;
        }

        unsigned long sumaIntervalos = 0;

        int cantidad;

        if(bufferLleno) {
          cantidad = nInter;
        }
        else {
          cantidad = indice;
        }
        
        for(int i=0; i<cantidad; i++) {
          sumaIntervalos += intervalos[i];
        }
        
        float promedioIntervalo = sumaIntervalos / (float)cantidad;
        float bpmActual = 60000.0 / promedioIntervalo;
        bpmFilt = aphBPM * bpmActual + (1 - aphBPM) * bpmFilt;
        bpm = (int)bpmFilt;
        ultBPMVal = millis();
        Serial.print("BPM: ");
        Serial.println(bpm);
        mostrarBPM(bpm);
      }
      ultLat = tiempoActual;
  }

  if(senalAmplificada < umbral - 0.5) {
      picoDet = false;
  }

  if(millis() - ultBPMVal > 3000) {
      mostrarSinDedo();
  }

  // SERIAL PLOTTER
  Serial.print(senalAmplificada);
  Serial.print(",");
  Serial.println(umbral);
  lAnterior = senalAmplificada;

  delay(5);

}
