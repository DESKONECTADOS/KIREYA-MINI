//MOTORES
const int pwma = 3;
const int ML_A = 4;
const int ML_B = 5;
const int pwmb = 9;
const int MR_A = 8;
const int MR_B = 7;

//SENSORES
const int fder = 12;
const int fizq = 10;
const int der = 13;
const int izq = 11;
const int lin1 = A0;
const int lin2 = A1;
const int REMOTE = 0;

//SENSORES LECTURAS
int sder;
int sizq;
int sfder;
int sfizq;
int sensline1;
int sensline2;
int lineval;
int SensVal;
int ON = 1;



void setup() {
  pinMode(pwma, OUTPUT);
  pinMode(ML_A, OUTPUT);
  pinMode(ML_B, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(MR_A, OUTPUT);
  pinMode(MR_B, OUTPUT);
  pinMode(REMOTE, INPUT);
  pinMode(der, INPUT);
  pinMode(izq, INPUT);
  pinMode(lin1, INPUT);
  pinMode(lin2, INPUT);
  
  Serial.begin(9600);

}



void loop() {

  while(digitalRead(REMOTE) == 1){

  lineval = linevalue();
  SensVal = SensValor();

Serial.println(lineval);
  
  
  switch (lineval){
    case 0:
    switch(SensVal){
      
      case 0:
          adelante();
          analogWrite(pwma, 100);
          analogWrite(pwmb, 100);
          Serial.println("Adelante");
          delay(50);
          break;
 
      case 1:
           derecha();
          analogWrite(pwma, 220);
          analogWrite(pwmb, 220);
          Serial.println("Derecha");
          delay(50);
          break;
      case 2:
          derecha();
          analogWrite(pwma, 170);
          analogWrite(pwmb, 170);
          Serial.println("Derecha");
          delay(50);
          break;

       case 3:
          derecha();
          analogWrite(pwma, 150);
          analogWrite(pwmb, 150);
          Serial.println("Adelante");
          delay(50);
          break;

        case 4:
          izquierda();
          analogWrite(pwma, 150);
          analogWrite(pwmb, 150);
          Serial.println("Izquierda");
          delay(50);
          break;
       
        case 6:
          adelante();
          analogWrite(pwma, 220);
          analogWrite(pwmb, 220);
          Serial.println("Adelante");
          delay(50);
          break;
        
        case 7: //Si tiene bandera y el sumo esta de lado derecho
          derecha();
          analogWrite(pwma, 200);
          analogWrite(pwmb, 200);
          Serial.println("bandera");
          delay(50);
          break;

        case 8: //si esta a izquierda
          izquierda();
          analogWrite(pwma, 170);
          analogWrite(pwmb, 170);
          Serial.println("Izquierda");
          delay(50);
          break;

        case 12:
          izquierda();
          analogWrite(pwma, 160);
          analogWrite(pwmb, 160);
          Serial.println("Izquierda");
          delay(50);
          break;

  }
  break;

  case 1:
         atras();
          Serial.println("Linea 1");
          analogWrite(pwma, 250);
          analogWrite(pwmb, 250);
          delay(200);
         derecha();
          analogWrite(pwma, 200);
          analogWrite(pwmb, 200);
          delay(200);
  
          break;


  case 2:
         atras();
          Serial.println("Linea 2");
          analogWrite(pwma, 250);
          analogWrite(pwmb, 250);
          delay(200);
         izquierda();
          analogWrite(pwma, 200);
          analogWrite(pwmb, 200);
          delay(200);
  
          break;

    case 3: 
         atras();
         analogWrite(pwma, 250);
          analogWrite(pwmb, 250);
          delay(200);
          izquierda();
          analogWrite(pwma, 200);
          analogWrite(pwmb, 200);
          Serial.println("linea los dos");
          delay(150);
          
          break;
  }
 }
 detenido();
}


void adelante(){
  digitalWrite(ML_A, 1);
  digitalWrite(ML_B, 0);
  digitalWrite(MR_A, 1);
  digitalWrite(MR_B, 0);
}

void derecha(){
  digitalWrite(ML_A, 0);
  digitalWrite(ML_B, 1);
  digitalWrite(MR_A, 1);
  digitalWrite(MR_B, 0);
}

void izquierda(){
  digitalWrite(ML_A, 1);
  digitalWrite(ML_B, 0);
  digitalWrite(MR_A, 0);
  digitalWrite(MR_B, 1);
}

void atras(){
  digitalWrite(ML_A, 0);
  digitalWrite(ML_B, 1);
  digitalWrite(MR_A, 0);
  digitalWrite(MR_B, 1);
}

  void detenido(){
  digitalWrite(ML_A, 0);
  digitalWrite(ML_B, 0);
  digitalWrite(MR_A, 0);
  digitalWrite(MR_B, 0);
}


byte SensValor(){
  byte sder = digitalRead(der);
  byte sfder = digitalRead(fder)*2;
  byte sfizq = digitalRead(fizq)*4;
  byte sizq = digitalRead(izq)*8;

  byte SumaTotal = sizq + sfizq + sfder + sder;
  return SumaTotal;
}

int linevalue(){
  int sensline = ! digitalRead(lin1);
  int sensline2  = ! digitalRead(lin2)*2;
  int suma = sensline + sensline2;
  return suma;
}
