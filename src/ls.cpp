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

void lsAide(void){
    Serial.println("Commande ls :");
    Serial.println("fonction : affiche le contenu du repertoire courant sur carte SD");
    Serial.println("usage    : ls ");
}

int ls(String commande){
    int returnValue = NO_ERREUR;
    File directory;
    if (commande.equals("aide")){
        lsAide();
        return returnValue;
    } 
    // Serial.printf("Liste des fichiers : (a develloper)\n");
    // if (cdeTbl[1].isEmpty()){
    //     cdeTbl[1] = repertoire;
    // }
    if (isSdAvailable()){
        // Serial.println("ouverture du repertoire " + repertoire);
        directory = sdOpenRead(repertoire);
        if (!directory.isDirectory()) {
            Serial.println(repertoire + " n'est pas un répertoire");
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
            Serial.printf("%-25s", entry.name());
            // Serial.printf("<%s>", entry.name());
            if (cpt++ > 3) {
                Serial.println();
                cpt = 0;
            }
            // }
            entry.close();
            entry = directory.openNextFile();
        }
        Serial.println();
        directory.close();

    } else {
        Serial.println("Sd card non disponible");
        return ERREUR_SD_CARD_NON_DISPONIBLE;
    }
    return returnValue;
}