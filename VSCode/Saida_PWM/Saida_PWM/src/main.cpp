/*

  Cálculo de frequência:

  Freq Max = Clock/Resol.

  Exemplo -> 10 bits: 80e6/1024 = 78125HZ
  Exemplo ->  8 bits: 80E6/256  = 312500Hz
  Exemplo ->  5 bits: 80E6/32   = 2.5Hz

  Funções para configuração:

  ledcAttachPin(pin, ch);     // Associa o pino ao canal PWM
  ledcSetup(ch, freq, res);   // Canal utilizxado, frequência e resolução
  ledcWrite(ch, duty);        // Canal utilizado, duty cycle

  Exemplo de cálculo para Servo com frequência de PWM de 50hz e range de 0,6ms até 2,4ms, e 1,5ms 90º:

  100% --- 65535
    0% ---     0

  100% --- 20ms
     x --- 1,5ms (90º)
     x = 7,5%

  100% --- 65535
  7,5% --- x
     x = 4915

*/


// ==========================================================================================
// Bibliotecas
#include <Arduino.h>

// ==========================================================================================
// Mapeamento de hardware
#define pot1 2
#define pot2 4
#define pwm_test 13
#define servo 18
#define motor 19
#define buzzer 25


void setup() {

    pinMode(pwm_test, OUTPUT);
    pinMode(motor, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(servo, OUTPUT);

    // ledcAttachPin(pwm_test, 0);
    // ledcSetup(0, 800, 16);
    // ledcWrite(0, 30000);

    // ledcAttachPin(motor, 6);
    // ledcSetup(6, 1000, 16);
    // ledcWrite(6, 30000);

    // ledcAttachPin(buzzer, 6);
    // ledcSetup(6, 1000, 16);
    // ledcWrite(6, 30000);

    ledcAttachPin(servo, 9);
    ledcSetup(9, 50,16);
    ledcWrite(9, 4915);

    // Teste buzzer
    // digitalWrite(buzzer, HIGH);
    // delay(2000);
    // digitalWrite(buzzer, LOW);
    // delay(2000);

}

void loop() {

    unsigned duty1, duty2;

    // duty1 = map(analogRead(pot1), 0, 4095, 0, 65535);
    // ledcWrite(0, duty1);

    // duty2 = map(analogRead(pot2), 0, 4095, 0, 65535);
    // ledcWrite(6, duty2);

    // ledcWrite(9, 4915);
    // delay(2000);
    // ledcWrite(9, 7864);
    // delay(2000);
    // ledcWrite(9, 1966);

    // Controlando Servo pelo potenciômetro
    unsigned dutyServo;
    dutyServo = map(analogRead(pot1), 0, 4095, 1966, 7864);
    ledcWrite(9, dutyServo);
}