//---------------------------------------------------
//
//      commandes.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>

#include "analyseCommande.hpp"

#ifndef __COMMANDES__
    #define __COMMANDES__

    #define NB_COMMANDES    8

    extern int aide(String commande);
    extern int cat(String commande);
    extern int ls(String commande);
    extern int pwd(String commande);
    extern int cd(String commande);
    extern int env(String commande);
    extern int set(String commande);
    extern int unset(String commande);

    // la liste des commandes et des fonctions assiciées 
    // est a renseigner dans le fichier commandes.cpp
    extern const String listeCommandes[NB_COMMANDES];
    extern int (*functptr[])(String);
    extern int nb_commandes;
    extern String prompt;

#endif
