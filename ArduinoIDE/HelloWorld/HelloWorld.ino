/*
      Este programa tem a função de piscar o led onboard do ESP32, criando um HelloWorld. 
 
 */

void setup() {

    pinMode(2, OUTPUT);
    digitalWrite(2, LOW);
} // end void setup

void loop() {

    for(int i = 0; i < 10; i++)
    {
        digitalWrite(2, HIGH);
        delay(100);
        digitalWrite(2, LOW);
        delay(100);
    }

    delay(1000);
} // end void loop
