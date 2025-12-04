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
#include "gestionFlux.hpp"


void hystoryAide(void){
    fluxWriteln("fluxout", "Commande cp :");
    fluxWriteln("fluxout", "fonction : copie le contenu d'un fichier dans un autre fichier");
    fluxWriteln("fluxout", "usage    : cp <fichier source> <fichier destination>");
}


int hystory(struct_cde_data data){
    // decomposeCommande(commande, ' ');
    int returnValue=NO_ERREUR;
    if (data.commande.equals("aide")){
        hystoryAide();
        return returnValue;
    } 
    listeHistorique();
    return returnValue;
}