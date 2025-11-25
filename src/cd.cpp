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

void cdAide(void){
    Serial.println("Commande cd :");
    Serial.println("fonction : change de repertoire sur carte SD");
    Serial.println("usage    : cd <nom du repertoire>");
}

int cd(String commande){
    int returnValue = NO_ERREUR;
    String homeDir = getPwd(); 
    File dir = sdOpenDir(cdeTbl[1]); 
    if (! dir.isDirectory()){
        sdOpenDir(homeDir);
        Serial.println("ERREUR : " + cdeTbl[1] + " n'est pas un repertoire");
    }

    prompt = base_prompt + getPwd() + " > ";
    return returnValue;


    String repertoire = getPwd();
    if (commande.equals("aide")){
        cdAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        if (cdeTbl[1].isEmpty()){
            Serial.println("ERREUR : manque nom de repertoire");
            returnValue = ERREUR_FILE_NOT_FOUND;
        } else {
            Serial.println("cd => On essaie d'ouvrir : " + cdeTbl[1]);
            if (cdeTbl[1].equals("..")){
                Serial.println("on remonte au repertoire parent");
                if (repertoire.length() == 0){
                    Serial.println("On est deja a la racine");
                } else {
                    int lastSlashIndex = repertoire.lastIndexOf('/');
                    if (lastSlashIndex == 0) {
                        // Retour à la racine
                        repertoire = "";
                        prompt = base_prompt;
                    } else {
                        repertoire = repertoire.substring(0, lastSlashIndex);
                        prompt = base_prompt + repertoire + " > ";
                        // sdOpen(repertoire);
                    }
                }
            } else {
                Serial.println("on va dans le repertoire " + cdeTbl[1]); 
                File directory = sdOpenDir(repertoire + "/" + cdeTbl[1]);
                if (directory){
                    if (directory.isDirectory()){
                        Serial.println(cdeTbl[1] + " est un repertoire, on y accede");
                        // directory = sdOpen(cdeTbl[1]);
                        if (!repertoire.equals("")){
                            repertoire = repertoire + "/" + directory.name();
                        } else {
                            repertoire = repertoire + directory.name();
                        }
                        // Serial.println("nouveau pwd : " + repertoire);
                        // repertoire = directory.name();
                        prompt = base_prompt + repertoire + " > ";
                    } else {
                        Serial.println("ERREUR : " + cdeTbl[1] + " n'est pas un repertoire");
                        returnValue = ERREUR_FILE_NOT_FOUND;                
                    }
                    directory.close();
                } else {
                    Serial.println("ERREUR : " + cdeTbl[1] + " n'existe pas");
                    returnValue = ERREUR_FILE_NOT_FOUND;
                }
            }
            setPwd(repertoire);
        }
    } else {
        Serial.println("Carte SD non disponible");
        returnValue=ERREUR_SD_CARD_NON_DISPONIBLE;
    }
    return returnValue;
}