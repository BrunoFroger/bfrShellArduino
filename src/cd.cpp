//---------------------------------------------------
//
//      cd.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"
#include "commandes.hpp"
#include "datas.hpp"
#include "sd.hpp"
#include "gestionFlux.hpp"
#include "commandes.hpp"

void cdAide(void){
    fluxWriteln("fluxout", "Commande cd :");
    fluxWriteln("fluxout", "fonction : change de repertoire sur carte SD");
    fluxWriteln("fluxout", "usage    : cd <nom du repertoire>");
}

int cd(struct_cde_data data){
    int returnValue = NO_ERREUR;
    String repertoire = getPwd();
    if (data.commande.equals("aide")){
        cdAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        String homeDir = getPwd(); 
        File dir = sdOpenDir(cdeTbl[1]); 
        if (! dir.isDirectory()){
            sdOpenDir(homeDir);
            fluxWriteln("fluxerr", cdeTbl[1] + " n'est pas un repertoire");
            returnValue=ERREUR_FILE_NOT_FOUND;
        }
    } else {
        fluxWriteln("fluxerr", "Carte SD non disponible");
        returnValue=ERREUR_SD_CARD_NON_DISPONIBLE;
    }
    prompt = base_prompt + getPwd() + " > ";
    return returnValue;
}