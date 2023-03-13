/* 
 *  
 *  Este programa tem a função de apresentar o uso das entradas analógicas
 *  
 */
// ========================================================================================================================================
// --- Mapeamento de hardware
#define out1 32
#define out2 33
#define an1   4
#define an2   2

void setup() {
  
   pinMode(out1, OUTPUT);
   pinMode(out2, OUTPUT);

   digitalWrite(out1, LOW);
   digitalWrite(out2, LOW);

   Serial.begin(115200);
}

void loop() {

    float voltage1 = analogRead(an1) * (3.3/4095);
    float voltage2 = analogRead(an2) * (3.3/4095);

    if(voltage1 > 1.0)  digitalWrite(out1, HIGH);
    else                digitalWrite(out1, LOW);

    if(voltage2 > 2.0) digitalWrite(out2, HIGH);
    else               digitalWrite(out2, LOW);
    
//
//    Serial.print("Tensão 1: ");
//    Serial.print(voltage1);
//    Serial.print("V            ");
//    Serial.print("Tensão 2: ");
//    Serial.print(voltage2);
//    Serial.println("V");
//    delay(1000);

  /*
    Serial.print(analogRead(an1));
    Serial.print("      ");
    Serial.println(analogRead(an2));
    delay(741);
  */
}
