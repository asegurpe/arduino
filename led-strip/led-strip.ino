// Led strip controller 0.2
// Property of ON-LASER Systems & Applications, SL

#include <LedStrip.h>
#include "config.h"


//Declaració dels capçals
int llista[] = LED_SECTIONS;
byte colorTable[][3] = COLOR_TABLE;

LedStrip ledStrip = LedStrip(llista, sizeof(llista)/sizeof(llista[0]), colorTable); 
char head;
char color;
char estat;
String missatge;

void setup(){  
  Serial.begin(BAUDRATE);
  Serial.setTimeout(SERIAL_TIMEOUT);
  //ledStrip.set('0','W','1'); //Inicialitzem amb el color blanc
}

void loop(){

  if (Serial.available() > 0){
    //Llegir port sèrie
    missatge = Serial.readStringUntil(EOT);

    //Descodificar trama sèrie
    head = missatge[0];
    color = missatge[1];
    estat = missatge[2];

    //Enviar ACK / NCK
    if(ledStrip.hasDefined(head, color, estat)){
      respondre((String)ACK+missatge+EOT);  // Canvi per retornar ACK amb info sobre la comana a la que pertany
      ledStrip.set(head, color, estat);  
    } else {
      respondre((String)NCK+missatge+EOT); // Canvi per retornar ACK amb info sobre la comana a la que pertany
    }
  }  
  ledStrip.update();
}

void respondre(String resposta){
  if (Serial.availableForWrite()){
    Serial.println(resposta);
  }
}
