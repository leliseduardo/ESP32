// ===============================================================================================
// --- Inclusão de bibliotecas ---
#include <Arduino.h>
#include "leituraBotoes.hpp"


// ===============================================================================================
// --- Mapeamento de hardware ---
#define bot1 18
#define bot2 19
#define out1 15
#define out2 4
#define out3 5

// ===============================================================================================
// --- Declaração de objetos ---
kb_rd mybts(bot1, bot2);

void setup() {
  
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out2, OUTPUT);

  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
  digitalWrite(out3, LOW);
}

void loop() {
  
  if(mybts.read_bt(0,130)) digitalWrite(out1, !digitalRead(out1));

  if(mybts.read_bt(1,130)) digitalWrite(out2, !digitalRead(out2));
}