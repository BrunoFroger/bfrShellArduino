//---------------------------------------------------
//
//      aide.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"
#include "commandes.hpp"
#include "gestionFlux.hpp"

int aide(struct_cde_data data){
    char buffer[255];
    char buffer1[255];
    int returnValue=NO_ERREUR;
    int cpt = 0;
    if (cdeTbl[1].length() == 0){
        fluxWriteln("fluxout", "Liste des commandes disponibles : ");
        for (int i=0 ; i < NB_COMMANDES ; i++){
            listeCommandes[i].toCharArray(buffer1,255);
            sprintf(buffer, "%15s", buffer1);
            fluxWrite("fluxout", buffer);
            if (cpt++ >= 4) {
                fluxWriteln("fluxout", "");
                cpt = 0;
            }
        }
        fluxWriteln("fluxout", "");
        fluxWriteln("fluxout", "Pour l'aide d'une commande spécifique tapez : aide <commnde>");
    } else {
        fluxWriteln("fluxout", "aide de la fonction " + cdeTbl[1]);
        for (int i = 0 ; i < NB_COMMANDES ; i++){
            if (cdeTbl[1].equals(listeCommandes[i])){
                data.commande="aide";
                returnValue=(*functptr[i])(data);
            }
        }
    }
    return returnValue;
}