//----------------------------------------------
//
//      main.cpp
//
//----------------------------------------------

#include <Arduino.h>

#include "datas.hpp"
#include "analyseCommande.hpp"
#include "sd.hpp"
#include "historique.hpp"
#include "erreurs.hpp"

String saisie;
File *fluxInput, *fluxOutput;


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
  prompt = base_prompt + getPwd() + " > ";


  Serial.println("+-------------------------------+");
  Serial.println("+                               +");
  Serial.println("+        Arduino SD shell       +");
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
        Serial.println("main : saisie = " + saisie);
        int res = analyseCommande(saisie);
        // Serial.println("resultat commande : " + String(res));
        if (!saisie.equals("history") && (res == NO_ERREUR)) storeHistorique(saisie);
        // if (!saisie.equals("history") ) storeHistorique(saisie);
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
        // char buffer[50]; sprintf(buffer, "\ncaractere special : %02x", carlu);Serial.println(buffer);
        int pos;
        switch (carlu)
        {
          case 0x08:  //BS backspace
            pos=saisie.length()-1;
            saisie=saisie.substring(0,pos);
            Serial.println();
            Serial.print(prompt + saisie);
            break;
          case 0x1b:  // ESC (touches de fonction)
            carlu = Serial.read(); // on lit le caractère
            if (carlu == '['){  // c'est une touche spéciale
              carlu = Serial.read(); // on lit le caractère
              switch(carlu){
                case 'A' :
                  // Serial.println("fleche Haut");
                  saisie = getHistoriqueUp();
                  Serial.println();
                  Serial.print(prompt + saisie);
                  break;
                case 'B' :
                  // Serial.println("fleche bas");
                  saisie = getHistoriqueDown();
                  Serial.println();
                  Serial.print(prompt + saisie);
                  break;
                case 'C' :
                  // Serial.println("fleche Droite");
                  break;
                case 'D' :
                  // Serial.println("fleche Gauche");
                  break;
              }
            }
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
