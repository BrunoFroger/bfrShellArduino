//---------------------------------------------------
//
//      completion.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <Arduino.h>
#include <string.h>

#include "commandes.hpp"
#include "gestionFlux.hpp"

String completion(struct_cde_flux flux, String saisie){
    if (saisie.equals("")) return "";
    // Serial.println("debut de completion");
    String listeCompletion = "";
    for (int i = 0 ; i < NB_COMMANDES ; i++){
        String commande = listeCommandes[i];
        if (commande.startsWith(saisie)) {
            listeCompletion += commande + " ";
        }
    }
    int pos=listeCompletion.length()-1;
    listeCompletion=listeCompletion.substring(0,pos);
    pos = listeCompletion.lastIndexOf(" ");
    // Serial.println("liste completion : <" + listeCompletion + ">");
    // Serial.println("nb espaces dans liste completion : " + String(pos));
    if (pos == -1 ){
        return listeCompletion;
    }
    if (listeCompletion.length() > 0){
        fluxWrite(flux.fluxout, "\n" + listeCompletion);
        return saisie;
    }
    // Serial.println("aucune completion trouvee");
    return "";
}