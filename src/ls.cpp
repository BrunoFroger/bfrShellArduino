//---------------------------------------------------
//
//      ls.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"
#include "commandes.hpp"
#include "sd.hpp"
#include "gestionFlux.hpp"
#include "commandes.hpp"

void lsAide(void){
    fluxWriteln("fluxout", "Commande ls :");
    fluxWriteln("fluxout", "fonction : affiche le contenu du repertoire courant sur carte SD");
    fluxWriteln("fluxout", "usage    : ls ");
}

int ls(struct_cde_data data){
    int returnValue = NO_ERREUR;
    File directory;
    if (data.commande.equals("aide")){
        lsAide();
        return returnValue;
    } 
    String dir;
    // Serial.printf("Liste des fichiers : (a develloper)\n");
    if (! cdeTbl[1].isEmpty()){
        dir = cdeTbl[1];
    } else {
        dir = getPwd();
    }
    if (isSdAvailable()){
        // Serial.println("ls : ouverture du repertoire <" + dir + ">");
        String homeDir = getPwd();
        directory = sdOpenDir(dir);
        if (!directory.isDirectory()) {
            fluxWriteln("fluxerr", "ls : " + dir + " n'est pas un répertoire");
            return ERREUR_FILE_NOT_FOUND;
        }
        File entry = directory.openNextFile();
        int cpt=0;
        while (entry) {
            // if (entry.isDirectory()) {
            // Serial.print("Dossier : ");
            // Serial.println(entry.name());
            // // listFiles(entry.name()); // Appel récursif pour les sous-dossiers
            // } else {
            // Serial.print("Fichier : ");
            char buffer[50];
            sprintf(buffer, "%-25s", entry.name());
            fluxWrite("fluxout", String(buffer));
            // Serial.printf("<%s>", entry.name());
            if (cpt++ > 3) {
                fluxWriteln("fluxout", "");
                cpt = 0;
            }
            // }
            entry.close();
            entry = directory.openNextFile();
        }
        fluxWriteln("fluxout", "");
        directory.close();
        sdOpenDir(homeDir);

    } else {
        fluxWriteln("fluxerr", "Sd card non disponible");
        return ERREUR_SD_CARD_NON_DISPONIBLE;
    }
    return returnValue;
}