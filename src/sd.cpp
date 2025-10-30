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

File sdOpen(String filename){
    File fic;
    for (int i = 0 ; i < NB_PIPES ; i++){
        if (tblPipe[i].filename.length() == 0){
            if (SD.exists(filename)){
                fic = SD.open(filename);
                tblPipe[i].filename=filename;
                tblPipe[i].fic=&fic;
                return fic;
            }
        }
    }
    return fic;
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