//---------------------------------------------------
//
//      cd.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"
#include "commandes.hpp"
#include "datas.hpp"
#include "sd.hpp"

void cdAide(void){
    Serial.println("Commande cd :");
    Serial.println("fonction : change de repertoire sur carte SD");
    Serial.println("usage    : cd <nom du repertoire>");
}

int cd(String commande){
    int returnValue = NO_ERREUR;
    String repertoire = getPwd();
    if (commande.equals("aide")){
        cdAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        String homeDir = getPwd(); 
        File dir = sdOpenDir(cdeTbl[1]); 
        if (! dir.isDirectory()){
            sdOpenDir(homeDir);
            Serial.println("ERREUR : " + cdeTbl[1] + " n'est pas un repertoire");
        }
    } else {
        Serial.println("Carte SD non disponible");
        returnValue=ERREUR_SD_CARD_NON_DISPONIBLE;
    }
    prompt = base_prompt + getPwd() + " > ";
    return returnValue;
}