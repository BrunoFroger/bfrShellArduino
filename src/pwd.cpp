//---------------------------------------------------
//
//      pwd.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"
#include "commandes.hpp"
#include "sd.hpp"

void pwdAide(void){
    Serial.println("Commande pwd :");
    Serial.println("fonction : affiche le nom du repertoire courant sur carte SD");
    Serial.println("usage    : pwd ");
}

int pwd(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        pwdAide();
        return returnValue;
    } 
    Serial.println(getPwd());
    return returnValue;
}