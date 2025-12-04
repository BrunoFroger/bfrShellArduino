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
#include "gestionFlux.hpp"
#include "datas.hpp"
#include "commandes.hpp"
#include "commandes.hpp"


void getAnalogPinAide(void){
    fluxWriteln("fluxout", "Commande getAnalogPin :");
    fluxWriteln("fluxout", "fonction : affiche la valeur d'une entrée analogique");
    fluxWriteln("fluxout", "usage    : getAnalogPin <pin number>");
}

int getAnalogPin(struct_cde_data data){
    // int returnValue = -1;
    if (data.commande.equals("aide")){
        getAnalogPinAide();
        return 0;
    }
    // TODO A valider
    return analogRead(cdeTbl[1].toInt());
}

void getDigitalPinAide(void){
    fluxWriteln("fluxout", "Commande getDigitalPin :");
    fluxWriteln("fluxout", "fonction : affiche la valeur d'une entrée digitale");
    fluxWriteln("fluxout", "usage    : getDigitalPin <pin number>");
}

int getDigitalPin(struct_cde_data data){
    int returnValue = NO_ERREUR;
    if (data.commande.equals("aide")){
        getDigitalPinAide();
        return returnValue;
    }
    // TODO A valider
    return digitalRead(cdeTbl[1].toInt());
}

void setDigitalPinAide(void){
    fluxWriteln("fluxout", "Commande setDigitalPin :");
    fluxWriteln("fluxout", "fonction : modifie la valeur d'une sortie digitale");
    fluxWriteln("fluxout", "usage    : setDigitalPin <pin number> <valeur>");
}

int setDigitalPin(struct_cde_data data){
    int returnValue = NO_ERREUR;
    if (data.commande.equals("aide")){
        setDigitalPinAide();
        return returnValue;
    }
    // TODO A valider
    digitalWrite(cdeTbl[1].toInt(), cdeTbl[2].toInt());
    return returnValue;
}