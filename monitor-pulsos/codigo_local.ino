const int pht = 34;
const int nInter = 4;

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

int bpm = 0;
int tMuerto = 400;
int indice = 0;

unsigned long intervalos[nInter];

bool bufferLleno = false;


void setup() {

  Serial.begin(115200);
  for(int i=0; i<nInter; i++) {
    intervalos[i]=0;
  }
}



void loop() {
  long suma = 0;
  for(int i=0; i<10; i++) {
    suma += analogRead(pht);
    delay(2);
  }

  float lectura = suma / 10.0;

  signFilt = aphSign*lectura+(1-aphSign)*signFilt;

  pBase = aphBase*signFilt+(1-aphBase)*pBase;

  float senalAmplificada=signFilt-pBase)*5;

  float umbral = offset;

  if(senalAmplificada>umbral && lAnterior>senalAmplificada && !picoDet && millis() - ultLat > tMuerto) {
      picoDet = true;
      unsigned long tiempoActual = millis();

      unsigned long intervalo = tiempoActual-ultLat;

      if(intervalo>300 && intervalo<2000) {
        intervalos[indice] = intervalo;
        indice++;

        if(indice>=nInter) {
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

        bpmFilt = aphBPM*bpmActual+(1-aphBPM)*bpmFilt;
        bpm = (int)bpmFilt;

        Serial.print("BPM: ");
        Serial.println(bpm);
      }
      ultLat = tiempoActual;
  }

  if(senalAmplificada<umbral-0.5) {
      picoDet = false;
  }

  lAnterior = senalAmplificada;
  delay(5);
}
