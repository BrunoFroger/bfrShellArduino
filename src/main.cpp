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
#include "gestionFlux.hpp"
#include "commandes.hpp"

String saisie;

//=================================================
//
//      setup
//
//=================================================
void setup() {
  Serial.begin(115200);
  int timeoutInitSerial = 100;
  while (timeoutInitSerial-- > 0)
  {
      if (Serial)
          break;
      delay(10);
  }
  delay(1000);
  fluxWriteln("fluxout", "Serial initialized");

  sdInit();
  prompt = base_prompt + getPwd() + " > ";

  main_cde_flux.fluxin="fluxin";
  main_cde_flux.fluxout="fluxout";
  main_cde_flux.fluxerr="fluxerr";
  main_cde_data.cdeFlux = main_cde_flux;

  fluxWriteln("fluxout", "+-------------------------------+");
  fluxWriteln("fluxout", "+                               +");
  fluxWriteln("fluxout", "+        Arduino SD shell       +");
  fluxWriteln("fluxout", "+                               +");
  fluxWriteln("fluxout", "+-------------------------------+");
  fluxWrite("fluxout", prompt);
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

  cardispo = fluxAvailable("fluxin");

  while(cardispo > 0) // tant qu'il y a des caractères à lire
  {
      carlu = fluxRead("fluxin"); // on lit le caractère
      if (carlu == '\n'){
        fluxWrite("fluxout", String(carlu)); // puis on le renvoi à l’expéditeur tel quel
        main_cde_data.commande = saisie;
        int res = analyseCommande(main_cde_data);
        if (!saisie.equals("history") && (res == NO_ERREUR)) storeHistorique(saisie);
        fluxFlush("fluxout");
        fluxWrite("fluxout", prompt);
        saisie="";
        continue;
      }
      if ((carlu >= 32) && (carlu <= 127)) {
        saisie += carlu;
        fluxWrite("fluxout", String(carlu)); // puis on le renvoi à l’expéditeur tel quel
      } else {
        int pos;
        switch (carlu)
        {
          case 0x08:  //BS backspace
            pos=saisie.length()-1;
            saisie=saisie.substring(0,pos);
            fluxWriteln("fluxout", "");
            fluxWrite("fluxout", prompt + saisie);
            break;
          case 0x1b:  // ESC (touches de fonction)
            carlu = fluxRead("fluxin"); // on lit le caractère
            if (carlu == '['){  // c'est une touche spéciale
              carlu = fluxRead("fluxin"); // on lit le caractère
              switch(carlu){
                case 'A' :  // fleche haut
                  saisie = getHistoriqueUp();
                  fluxWriteln("fluxout", "");
                  fluxWrite("fluxout", prompt + saisie);
                  break;
                case 'B' : // fleche bas
                  saisie = getHistoriqueDown();
                  fluxWriteln("fluxout", "");
                  fluxWrite("fluxout", prompt + saisie);
                  break;
                case 'C' : // fleche droite
                  break;
                case 'D' : // fleche gauche
                  break;
              }
            }
            break;
          
          default:
            break;
        }
      }
      cardispo = fluxAvailable("fluxin"); // on relit le nombre de caractères dispo
  }
  delay(100);
}
