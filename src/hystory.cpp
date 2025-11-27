//---------------------------------------------------
//
//      hystory.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "analyseCommande.hpp"
#include "erreurs.hpp"
#include "historique.hpp"


void hystoryAide(void){
    Serial.println("Commande cp :");
    Serial.println("fonction : copie le contenu d'un fichier dans un autre fichier");
    Serial.println("usage    : cp <fichier source> <fichier destination>");
}


int hystory(String commande){
    // decomposeCommande(commande, ' ');
    int returnValue=NO_ERREUR;
    if (commande.equals("aide")){
        hystoryAide();
        return returnValue;
    } 
    listeHistorique();
    return returnValue;
}