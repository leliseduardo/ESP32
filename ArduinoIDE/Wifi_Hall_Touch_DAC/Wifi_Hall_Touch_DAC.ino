/* 
 *      Aula 5 do módulo 2 - Pinos touch, sensor hall
 *  
 *  
 */

// ==========================================================================================================================================
// UART
//#define RX2 16
//#define TX2 17

// ==========================================================================================================================================
// DAC
//uint8_t val = 0;
//bool control = 0;
//uint8_t  sine_wave[256] = {
//  0x80, 0x83, 0x86, 0x89, 0x8C, 0x90, 0x93, 0x96,
//  0x99, 0x9C, 0x9F, 0xA2, 0xA5, 0xA8, 0xAB, 0xAE,
//  0xB1, 0xB3, 0xB6, 0xB9, 0xBC, 0xBF, 0xC1, 0xC4,
//  0xC7, 0xC9, 0xCC, 0xCE, 0xD1, 0xD3, 0xD5, 0xD8,
//  0xDA, 0xDC, 0xDE, 0xE0, 0xE2, 0xE4, 0xE6, 0xE8,
//  0xEA, 0xEB, 0xED, 0xEF, 0xF0, 0xF1, 0xF3, 0xF4,
//  0xF5, 0xF6, 0xF8, 0xF9, 0xFA, 0xFA, 0xFB, 0xFC,
//  0xFD, 0xFD, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF,
//  0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD,
//  0xFD, 0xFC, 0xFB, 0xFA, 0xFA, 0xF9, 0xF8, 0xF6,
//  0xF5, 0xF4, 0xF3, 0xF1, 0xF0, 0xEF, 0xED, 0xEB,
//  0xEA, 0xE8, 0xE6, 0xE4, 0xE2, 0xE0, 0xDE, 0xDC, 
//  0xDA, 0xD8, 0xD5, 0xD3, 0xD1, 0xCE, 0xCC, 0xC9,
//  0xC7, 0xC4, 0xC1, 0xBF, 0xBC, 0xB9, 0xB6, 0xB3,
//  0xB1, 0xAE, 0xAB, 0xA8, 0xA5, 0xA2, 0x9F, 0x9C,
//  0x99, 0x96, 0x93, 0x90, 0x8C, 0x89, 0x86, 0x83,
//  0x80, 0x7D, 0x7A, 0x77, 0x74, 0x70, 0x6D, 0x6A,
//  0x67, 0x64, 0x61, 0x5E, 0x5B, 0x58, 0x55, 0x52,
//  0x4F, 0x4D, 0x4A, 0x47, 0x44, 0x41, 0x3F, 0x3C,
//  0x39, 0x37, 0x34, 0x32, 0x2F, 0x2D, 0x2B, 0x28,
//  0x26, 0x24, 0x22, 0x20, 0x1E, 0x1C, 0x1A, 0x18,
//  0x16, 0x15, 0x13, 0x11, 0x10, 0x0F, 0x0D, 0x0C,
//  0x0B, 0x0A, 0x08, 0x07, 0x06, 0x06, 0x05, 0x04,
//  0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01,
//  0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03,
//  0x03, 0x04, 0x05, 0x06, 0x06, 0x07, 0x08, 0x0A,
//  0x0B, 0x0C, 0x0D, 0x0F, 0x10, 0x11, 0x13, 0x15,
//  0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24,
//  0x26, 0x28, 0x2B, 0x2D, 0x2F, 0x32, 0x34, 0x37,
//  0x39, 0x3C, 0x3F, 0x41, 0x44, 0x47, 0x4A, 0x4D,
//  0x4F, 0x52, 0x55, 0x58, 0x5B, 0x5E, 0x61, 0x64,
//  0x67, 0x6A, 0x6D, 0x70, 0x74, 0x77, 0x7A, 0x7D
//};

// ==========================================================================================================================================
// WIFI
// Bibliotecas 
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// Dados da rede
const char *ssid = "Vero ";
const char *password = "Nabucodonosor";

// Objetos necessários
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Strings necessárias
String formattedDate;
String dayStamp;
String timeStamp;

void setup() {
  
    Serial.begin(115200);
    
// ==========================================================================================================================================
// Touch
//    pinMode(2, OUTPUT);
//    digitalWrite(2, LOW);
// ==========================================================================================================================================
// UART
//    pinMode(RX2, OUTPUT);
//    Serial2.begin(9600, SERIAL_8N1, RX2. TX2);
// ==========================================================================================================================================
// Wifi
    // Código para aguardar conexão WiFi
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED){
      
      delay(500);
      Serial.print("...");
    }

    // Imprime IP local
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    // Inicializa o NTPClient para captura do horário
    timeClient.begin();
    // Selecione o offset em múltiplos de 3600 (Brasília GMT-3), portanto -3x3600 = -10800
    timeClient.setTimeOffset(-10800); 
    
} // end void setup

void loop() {

// ==========================================================================================================================================
// Touch
//    Serial.println(touchRead(13));
//    delay(741);

//    if(touchRead(13) < 40)  digitalWrite(2, HIGH);
//    else                    digitalWrite(2, LOW);
// ==========================================================================================================================================
// Hall
//
//    Serial.println(hallRead());
//    delay(555);
// ==========================================================================================================================================
// UART
//    Serial2.write(0x30);
//    Serial2.write(0x31);
//    Serial2.write(0x32);
//    Serial2.print("Enviando uma frase");
//    delay(10);
// ==========================================================================================================================================
// DAC
// Onda quadrada
//    dacWrite(26,33);
//    delay(555);
//    dacWrite(26, 200);
//    delay(555);
// Onda dente de serra
//    dacWrite(26,val);
//    delayMicroseconds(100);
//    val++;
// Onda triangular
//    if(!control){
//        val++;
//        if(val>254) control = 1;
//    }
//    else{
//        val--;
//        if(val<1) control = 0;
//    } 
//    dacWrite(26,val);
//    delayMicroseconds(10);
// Onda senoidal
//    dacWrite(26, sine_wave[val]);
//    delayMicroseconds(10);
//    val++;
// ==========================================================================================================================================
// WIFI
    // Aguarda atualização
    while(!timeClient.update())
        timeClient.forceUpdate();

   // Captura data e hora no formato: 2018-05-28T16:00:13Z
   formattedDate = timeClient.getFormattedDate();

    // Captura data e imprime
    int splitT = formattedDate.indexOf("T");
    dayStamp = formattedDate.substring(0, splitT);
    Serial.print("Data: ");
    Serial.println(dayStamp);

    // Separa hora e imprime
    timeStamp = formattedDate.substring(splitT+1, formattedDate.length()-1);
    Serial.print("Hora: ");
    Serial.println(timeStamp);

    delay(1000);
    
} // end void loop
