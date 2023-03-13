/* 

        Este programa tem a função de piscar 3 leds com tempos diferentes, sem que o tempo de um interfira no tempo de outro. Isto é, o acionamento de uma saída não interfira
    no acionamento de outra saída.

        O programa funcionou perfeitamente
 */

 // Mapeamento de hardware
 #define out1 15
 #define out2  4
 #define out3  5

 // Constantes do projeto
 #define out1_delay 100
 #define out2_delay 200
 #define out3_delay 300

 // Variáveis globais
 int out1_cont = 0,
     out2_cont = 0,
     out3_cont = 0;

void setup() {
  
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    pinMode(out3, OUTPUT);

    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
}

void loop() {

    if(millis() - out1_cont >= out1_delay){
        
        digitalWrite(out1, !digitalRead(out1));
        out1_cont = millis();
    } // end if out1

    if(millis() - out2_cont >= out2_delay){
    
        digitalWrite(out2, !digitalRead(out2));
        out2_cont = millis();
    } // end if out2

    if(millis() - out3_cont >= out3_delay){

        digitalWrite(out3, !digitalRead(out3));
        out3_cont = millis();
    }
    
}
