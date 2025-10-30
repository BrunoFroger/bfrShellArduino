//---------------------------------------------------
//
//      pinFunction.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"


void getAnalogPinAide(void){
    Serial.println("Commande getAnalogPin :");
    Serial.println("fonction : affiche la valeur d'une entrée analogique");
    Serial.println("usage    : getAnalogPin <pin number>");
}

int getAnalogPin(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        getAnalogPinAide();
        return returnValue;
    }
    Serial.println("a developper");
    return returnValue;
}

void getDigitalPinAide(void){
    Serial.println("Commande getDigitalPin :");
    Serial.println("fonction : affiche la valeur d'une entrée digitale");
    Serial.println("usage    : getDigitalPin <pin number>");
}

int getDigitalPin(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        getDigitalPinAide();
        return returnValue;
    }
    Serial.println("a developper");
    return returnValue;
}

void setDigitalPinAide(void){
    Serial.println("Commande setDigitalPin :");
    Serial.println("fonction : modifie la valeur d'une sortie digitale");
    Serial.println("usage    : setDigitalPin <pin number>");
}

int setDigitalPin(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        setDigitalPinAide();
        return returnValue;
    }
    Serial.println("a developper");
    return returnValue;
}