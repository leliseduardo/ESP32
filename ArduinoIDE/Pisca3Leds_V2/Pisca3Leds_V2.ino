/* Aula 2 do módulo 2 do curso de ESP32

 Autor: Eduardo Lelis
 Novembro 2021
*/

// ============================================================================================================== //
// Mapeamento de hardware
#define out1 15
#define out2  4
#define out3  5

// ============================================================================================================== //
// Constantes do projeto
#define out1_time 100
#define out2_time 200
#define out3_time 300

// ============================================================================================================== //
// Variáveis do projeto
int out1_time_save = 0,
    out2_time_save = 0,
    out3_time_save = 0;
    
// ============================================================================================================== //
void setup() {
  
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    pinMode(out3, OUTPUT);

    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
} // end void setup

// ============================================================================================================== //
void loop() {

    if((millis()-out1_time) >= out1_time_save){

        digitalWrite(out1, !digitalRead(out1));
        out1_time_save = millis();
    } // end if out1

    if((millis()-out2_time) >= out2_time_save){

        digitalWrite(out2, !digitalRead(out2));
        out2_time_save = millis();
    } // end if out2

    if((millis()-out3_time) >= out3_time_save){

        digitalWrite(out3, !digitalRead(out3));
        out3_time_save = millis();
    } // end if out3
        
} // end void loop
