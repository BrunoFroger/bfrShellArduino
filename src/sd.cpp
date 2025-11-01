//---------------------------------------------------
//
//      commandes.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#include "erreurs.hpp"

#define NB_PIPES    10

const int chipSelect = 10;
int sdOk;
File *fic;
String repertoire = "/";

struct sdPipe{
    String filename;
    File *fic;
};

sdPipe tblPipe[NB_PIPES];

int sdInit(void){
    Serial.println("Initialisation de la carte SD...");

    for (int i=0 ; i < NB_PIPES ; i++){
        tblPipe[i].filename = "";
        tblPipe[i].fic = nullptr;
    }
    if (!SD.begin(chipSelect)) {
        Serial.println("Erreur d'initialisation de la carte SD");
        sdOk=0; 
    } else {
        Serial.println("Carte SD initialisée.");
        sdOk=1;
    }
    return sdOk;
}

int isSdAvailable(void){
    // Serial.println("fonction : isSdAvalaible = " + String(sdOk));
    if (! sdOk){
        Serial.println("Erreur : SD Card non disponible !");
    }
    return sdOk;
}

int fileExist(String filename){
    if (isSdAvailable()){
        return SD.exists(filename);
    }
    return 0;
}

File sdOpen(String filename, String mode){
    File fic;
    for (int i = 0 ; i < NB_PIPES ; i++){
        if (tblPipe[i].filename.length() == 0){
            if (SD.exists(filename)){
                if (mode.equals("R")){
                    fic = SD.open(filename, FILE_READ);
                } else if (mode.equals("W")){
                    fic = SD.open(filename, FILE_WRITE);
                } else {
                    return fic;
                }
                tblPipe[i].filename=filename;
                tblPipe[i].fic=&fic;
                return fic;
            }
        }
    }
    return fic;
}

File sdOpenRead(String filename){
    return sdOpen(filename, "R");
}

File sdOpenWrite(String filename){
    return sdOpen(filename, "W");
}

int sdRemove(String filename){
    if (fileExist(filename)){
        int res = SD.remove(filename);
        if (res == 0){
            Serial.println("ERREUR : Impossible d'effacer le fichier : " + filename);
        }
    } else {
        Serial.println("ERRUER : le fichier " + filename + " n'existe pas");
        return ERREUR_FILE_NOT_FOUND;
    }
    return NO_ERREUR;
}

int sdRmdir(String filename){
    if (fileExist(filename)){
        return SD.rmdir(filename);
    } else {
        Serial.println("ERRUER : le repertoire " + filename + " n'existe pas");
        return ERREUR_FILE_NOT_FOUND;
    }
    return NO_ERREUR;
}

int sdMkdir(String filename){
    int result = NO_ERREUR;
    if (! fileExist(filename)){
        int res = SD.mkdir(filename);
        if (res == 0){
            Serial.println("Erreur : impossible de creer le repertoire " + filename);
            result = ERREUR_CREATION_FILE;
        } else {
            result = NO_ERREUR;
        }
    } else {
        Serial.println("ERRUER : le repertoire " + filename + " existe déjà");
        result = ERREUR_FILE_EXIST;
    }
    return result;
}

File sdPipeOpen(String filename){
    // creer repertoire /tmp/pipes s'il n'existe pas
    // creer un fichier pour ce pipe
    File fic;
    if ( ! SD.exists("/tmp")){
        SD.mkdir("/tmp)");
    }
    for (int i = 0 ; i < NB_PIPES ; i++){
        if (tblPipe[i].filename.length() == 0){
            fic = SD.open(filename);
            tblPipe[i].filename=filename;
            tblPipe[i].fic=&fic;
            return fic;
        }
    }
    return fic;
}

void sdPipeClose(File fic){
    fic.close();
    // supprimer le fichier de pipe correspondant
}