//---------------------------------------------------
//
//      tache.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "tache.hpp"
#include "datas.hpp"
#include "erreurs.hpp"

tache::tache(struct_cde_flux flux, String commande){
    this->pid = getNewPid();
    this->init(flux, commande);
}

int tache::init(struct_cde_flux flux, String commande){
    int result = NO_ERREUR;
    this->flux = flux;
    int index = 0;
    int pos;
    while (commande.length() > 0){
        pos = commande.lastIndexOf(" ");
        this->parametres[index] = commande.substring(0, pos);
        commande = commande.substring(pos + 1);
    }
    this->commande = this->parametres[0];
    this->info();
    return result;
};

void tache::info(void){
    Serial.println("--------------------------");
    Serial.println(" Nom        : " + this->commande);
    Serial.println(" Pid        : " + this->pid);
    Serial.println(" Parametres :");
    for (int i = 1 ; i < MAX_PARAMETRES ; i++){
        if (this->parametres[i].length() > 0){
            Serial.println("       " + this->parametres[i]);
        } else break;
    }
    Serial.println("--------------------------");
};

String tache::getDatasConsole(){
    return this->datasConsole;
};

int tache::getPid(void){
    return this->pid;
}