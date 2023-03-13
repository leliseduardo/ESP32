// ====================================================================================
// Inclusão de bibliotecas
#include <Arduino.h>

// ====================================================================================
// Mapeamento de hardware
#define adc_in 4
#define light_ctr 19

// ====================================================================================
// Constantes do projeto
#define dt 100

// ====================================================================================
// Protótipo das funções
float pid_control(float meas, float setPoint); // Função para contronle pid

// ====================================================================================
// Variáveis globais
int time_upd = 0, pid_upd = 0;
float kp = 1.2, ki = 0.0, kd = 0.0;

// ====================================================================================
// Configurações iniciais
void setup() {
  
    Serial.begin(115200);
    pinMode(adc_in, INPUT);
    pinMode(light_ctr, OUTPUT);

    // Configura PWM de saída
    ledcAttachPin(light_ctr, 0);
    ledcSetup(0, 2000, 12);
    ledcWrite(0, 2048);
}

// ====================================================================================
// Programa principal
void loop() {
  
    // Teste do LDR na entrada analógica
    // Serial.println(analogRead(adc_in));
    // delay(741);

    // Teste do LDR de maneira inteligente, sem atrapalhar a execução do programa com delay
    if(millis()-time_upd >= 741){

        Serial.print("Light: ");
        Serial.println(analogRead(adc_in));
        time_upd = millis();
    }

    float pwmVal;

    if(millis()-pid_upd >= dt){

        pwmVal = pid_control(analogRead(adc_in), 2048.0);
        ledcWrite(0, pwmVal+2048); // Soma-se 2048, que é 50% de duty, para que o PWM aumente da metade até o
        // máximo caso necessite de mais putência e diminua da metade até o mínimo caso necessite menos potência
        pid_upd = millis();
    }
}


// ====================================================================================
// Desenvolvimento das funções
float pid_control(float meas, float setPoint){

    static float last_meas; // Variável static pois quer se manter o valor dela quando a execução sair da função
    float errorMeas, proportional, integral, derivative;

    errorMeas = setPoint - meas;

    proportional = kp * errorMeas;

    integral += (errorMeas * ki) * (dt/1000.0);

    derivative = ((last_meas - meas)*kd) * (dt/1000.0);
    last_meas = meas;

    return (proportional+integral+derivative);
}