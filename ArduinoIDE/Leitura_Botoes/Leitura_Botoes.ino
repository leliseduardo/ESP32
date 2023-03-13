/* 

      Este programa tem a função de fazer a leitura de dois botões a partir de duas entradas digitais do ESP32. Para isso, serão usados os pullups internos do ESP32, não necessitando
    de resistores externos para tal função. Este código fará uma leitura inteligente dos botões, onde o controlador irá esperar o botão ser solto para processar o que se necessita, no caso
    o acendimento de leds. Essa leitura será feita através de uma função específica para que o código fique mais limpo.

*/
// ====================================================================================================================================================================
// Mapeamento de hardware
#define out1 15
#define out2 4
#define out3 5
#define bot1 18
#define bot2 19

// ====================================================================================================================================================================
// Protótipo de funções
void leituraBotao();

// ====================================================================================================================================================================
// Setup
void setup() {

  pinMode(bot1, INPUT_PULLUP);
  pinMode(bot2, INPUT_PULLUP);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);

  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
  digitalWrite(out2, LOW);
}

// ====================================================================================================================================================================
// Loop
void loop() {
  
  leituraBotao();
}

// ====================================================================================================================================================================
// Funções auxiliares
void leituraBotao(){
  
   static int flag1 = 0, flag2 = 0;

   if(!digitalRead(bot1)) flag1 = 1;
   if(!digitalRead(bot2)) flag2 = 1;

   if(digitalRead(bot1) && flag1){

        digitalWrite(out1, !digitalRead(out1));
        flag1 = 0;
        delay(120);
   }

   if(digitalRead(bot2) && flag2){

        digitalWrite(out2, !digitalRead(out2));
        flag2 = 0;
        delay(120);
   }
}
