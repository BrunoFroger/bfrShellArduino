//---------------------------------------------------
//
//      scheduler.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <iostream>

#include "scheduler.hpp"
#include "erreurs.hpp"
#include "datas.hpp"

scheduler::scheduler(){
    this->init();
};

int scheduler::init(){
    int result = NO_ERREUR;
    for (int i = 0 ; i < MAX_TACHES ; i++){
        this->listeTaches[i] = nullptr;
    }
    return result;
};

String scheduler::getDatasConsole(int pid){
    String result;
    for (int i = 0 ; i < MAX_TACHES ; i++){
        if (this->listeTaches[i]->getPid() == pid){
            result = this->listeTaches[i]->getDatasConsole();
        }
    }
    return result;
};

int scheduler::newMoniteur(void){
    int newPid = -1;
    for (int i = 0 ; i < MAX_TACHES ; i++){
        if (this->listeTaches[i] == nullptr){
            newPid = getNewPid();
            listeTaches[i] = new tache(main_cde_flux, "moniteur");
        }
    }
    return newPid;
};