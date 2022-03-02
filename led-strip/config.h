#ifndef CONFIG_H
#define CONFIG_H

//Taula de distribució dels leds
//Per Q4003-D     amb tira de 96,6 cm / 58 LEDs): {5,8, 8,8, 8,8, 8,5}
//Per Q4003-3D1S  amb tira de 96,6 cm / 58 LEDs): {0,13, 8,8, 8,8, 8,5} tot i que caldrà provar si el 0 del 1B és admès o no...
#define LED_SECTIONS {9,9,8,8,8,8,10,10}  

//Baudrate
#define BAUDRATE 9600
#define SERIAL_TIMEOUT 1000

//Respostes del port sèrie
#define EOT '%'
#define ACK "ACK:"  //Missatge reconegut
#define NCK "NCK:"  //Missatge no reconegut

//Diccionari de colors
//https://github.com/FastLED/FastLED/wiki/Pixel-reference#setting-hsv-colors-
#define COLOR_TABLE {{'R',0,255},{'G',96,255},{'O',32,255},{'B',128,255},{'W',0,0},{'%',0,0}} //La taula sempre ha d'acabar amb el color "sentinella" {'%',0,0}

#endif
