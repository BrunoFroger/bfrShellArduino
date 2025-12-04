//---------------------------------------------------
//
//      historique.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>
#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"
#include "historique.hpp"
#include "gestionFlux.hpp"

String cdeHistorique[HISTORY_SIZE];
int indexHistorique = 0;
int nb_cde = 0;

String getHistoriqueUp(void){
    indexHistorique--;
    if (indexHistorique <= 0) indexHistorique = 0;
    return cdeHistorique[indexHistorique];
}
String getHistoriqueDown(void){
    indexHistorique++;
    if (indexHistorique >= nb_cde) indexHistorique = nb_cde;
    if (indexHistorique >= HISTORY_SIZE) indexHistorique = HISTORY_SIZE - 1;
    return cdeHistorique[indexHistorique];
}

void storeHistorique(String commande){
    for (int i = 0 ; i < HISTORY_SIZE - 1 ; i++){
        if (commande.equals(cdeHistorique[i])) return;
    }
    if (nb_cde < HISTORY_SIZE){
        cdeHistorique[nb_cde++] = commande;
    } else {
        for (int i = 0 ; i < HISTORY_SIZE - 1 ; i++){
            cdeHistorique[i] = cdeHistorique[i+1];
        }
        cdeHistorique[HISTORY_SIZE - 1] = commande;
    }
    indexHistorique=nb_cde;
}

void listeHistorique(void){
    for (int i = 0 ; i < HISTORY_SIZE ; i++){
        if (cdeHistorique[i].equals("")) break;
        char buffer[50], cde[30];
        cdeHistorique[i].toCharArray(cde,30);
        sprintf(buffer, " %2d : %-30s\n", i, cde);
        cdeHistorique->toCharArray(cde,30);
        fluxWrite("fluxout", buffer);
    }
}