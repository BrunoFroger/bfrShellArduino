//---------------------------------------------------
//
//      commandes.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>

#include "commandes.hpp"
#include "analyseCommande.hpp"

// pour ajouter de nouvelles fonctions :
//      - ajouter son nom dans la lite listeCommandes (par ordre alphabitique)
//      - ajouter le nom de la fonction dans la liste functptr (meme ordre que liste des commandes)
//      - ajouter le prototype de la fonction dans commandes.hpp
//      - creer et developper la fonction correspondante
//          - la fonction doit avoir un prototype : int nomFonction(char *)
//          - relancer le build 
//      - mettre a jour la variable nb_commandes

const String listeCommandes[]={"aide", "cat", "cd", "env", "getAnalogPin", "getDigitalPin", "grep", "ls", "pwd", "set", "setDigitalPin", "unset"};
int (*functptr[])(String) = { aide, cat, cd, env, getAnalogPin, getDigitalPin, grep, ls, pwd, set, setDigitalPin, unset } ;
