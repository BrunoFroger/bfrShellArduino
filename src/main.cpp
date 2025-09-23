//----------------------------------------------
//
//      main.cpp
//
//----------------------------------------------

#include <Arduino.h>

#include "datas.hpp"
#include "analyseCommande.hpp"
#include "sd.hpp"

String saisie;

//=================================================
//
//      setup
//
//=================================================
void setup() {
  //Serial.begin(115200);
  Serial.begin(115200);
  int timeoutInitSerial = 100;
  while (timeoutInitSerial-- > 0)
  {
      if (Serial)
          break;
      delay(10);
  }
  delay(1000);
  Serial.println("Serial initialized");

  sdInit();

  Serial.println("BFR Shell\n");

  Serial.println("+-------------------------------+");
  Serial.println("+                               +");
  Serial.println("+        fin setup              +");
  Serial.println("+                               +");
  Serial.println("+-------------------------------+");
  Serial.print(prompt);
}


//=================================================
//
//      loop
//
//=================================================
void loop() {
    // variable contenant le caractère à lire
  char carlu = 0;
  // variable contenant le nombre de caractère disponibles dans le buffer
  int cardispo = 0;

  cardispo = Serial.available();

  while(cardispo > 0) // tant qu'il y a des caractères à lire
  {
      carlu = Serial.read(); // on lit le caractère
      if (carlu == '\n'){
        Serial.print(carlu); // puis on le renvoi à l’expéditeur tel quel
        // Serial.read(); // on vide le buffer d'entree cr-lf
        // Serial.println("main : saisie = " + saisie);
        analyseCommande(saisie);
        Serial.flush();
        Serial.print(prompt);
        saisie="";
        continue;
      }
      if ((carlu >= 32) && (carlu <= 127)) {
        saisie += carlu;
        Serial.print(carlu); // puis on le renvoi à l’expéditeur tel quel
        // Serial.printf("%x", carlu); // puis on le renvoi à l’expéditeur tel quel
      } else {
        // char buffer[50];
        // sprintf(buffer, "\ncaractere special : %02x", carlu);
        // Serial.println(buffer);
        int pos;
        switch (carlu)
        {
          case 0x08:  //BS backspace
            pos=saisie.length()-1;
            saisie=saisie.substring(0,pos);
            Serial.println();
            Serial.print(prompt + saisie);
            break;
          
          default:
            break;
        }
      }
      cardispo = Serial.available(); // on relit le nombre de caractères dispo
  }
  // fgets(saisie, sizeof(saisie), stdin);
  // analyseCommande(saisie);
  delay(100);
}
