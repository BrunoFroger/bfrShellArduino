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
#include "commandes.hpp"

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

String getPwd(void){
    // Serial.println("SD.cpp : getPwd => <" + repertoire + ">");
    return repertoire;
}

void setPwd(String dir){
    // Serial.println("SD.cpp : setPwd => <" + dir + ">");
    SD.open(dir);
    repertoire = dir;
}

String getPath(String filename){
    String path;
    // if (filename.indexOf("/") > 0){
    //     return repertoire + "/" + filename;
    // }
    // if (repertoire.equals("/")){
    //     return filename;
    // }
    if (filename.startsWith("/")){
        path = filename;
    } else {
        path = repertoire + "/" + filename;
    }
    // if (path.startsWith("/") == true ){
    //     path = path.substring(1);
    // }
    // Serial.println("sd.cpp : getPath : input = " + filename + " / output = " + path);
    return path;
}

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
        analyseCommande("set pwd " + repertoire);
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
    String path = getPath(filename);
    if (isSdAvailable()){
        return SD.exists(path);
    }
    return ERREUR_SD_CARD_NON_DISPONIBLE;
}

File sdOpen(String filename, String mode){
    File fic;
    String path = getPath(filename);
    for (int i = 0 ; i < NB_PIPES ; i++){
        if (tblPipe[i].filename.length() == 0){
            if (SD.exists(path)){
                if (mode.equals("R")){
                    fic = SD.open(path, FILE_READ);
                    if (!fic){
                        Serial.println("ERREUR : impossible d'ouvrir le fichier en lecture " + path);
                        return fic;
                    }
                } else if (mode.equals("W")){
                    fic = SD.open(path, FILE_WRITE);
                    if (!fic){
                        Serial.println("ERREUR : impossible d'ouvrir le fichier en ecriture " + path);
                        return fic;
                    }
                }
            } else {
                if (mode.equals("W")){
                    fic = SD.open(path, FILE_WRITE);
                    if (!fic){
                        Serial.println("ERREUR : impossible d'ouvrir le fichier en ecriture " + path);
                        return fic;
                    }
                }
            }
            tblPipe[i].filename=path;
            tblPipe[i].fic=&fic;
            return fic;
        }
    }
    return fic;
}

File sdOpenDir(String filename){
    // Serial.println("sdOpenDir : ouverture repertoire : " + filename);
    if (filename.equals("")){
        // Serial.println("sdOpenDir : retour a ma racine");
        repertoire = "/";
    } else if (filename.equals("..")){
        // Serial.println("sdOpenDir : on remonte d'un repertoire");
        if (! repertoire.equals("/")){
            // Serial.println("sdOpenDir : <cd ..> on est dans le repertoire : " + repertoire);
            int pos = repertoire.lastIndexOf("/");
            if (pos > 1){
                repertoire.remove(pos);
            } else {
                repertoire = "/";
            }
            // Serial.println("sdOpenDir : <cd ..> nouveau repertoire : " + repertoire);
        } else {
            // Serial.println("sdOpenDir : on est deja a la racine");
        }
    } else if (filename.charAt(0) == '/') {
        // Serial.println("sdOpenDir : on accede a un path absolu : " + filename);
        repertoire = filename;
    } else if (repertoire.equals("/")) {
        // Serial.println("sdOpenDir : on est a la racine , on ouvre " + filename);
        repertoire = repertoire + filename;
    } else {
        // Serial.println("sdOpenDir : on est dans " + repertoire + " on ouvre le sous-repertoire " + filename);
        repertoire = repertoire + "/" + filename;
    }
    // Serial.println("sdOpenDir : nvx repertoire : " + repertoire);
    return SD.open(repertoire);
}

File sdOpenRead(String filename){
    String path = getPath(filename);
    return sdOpen(path, "R");
}

File sdOpenWrite(String filename){
    String path = getPath(filename);
    // Serial.println("sd.cpp : sdOpenWrite : tentative ouverture en W de " + path );
    return sdOpen(path, "W");
}

int sdRemove(String filename){
    String path = getPath(filename);
    if (fileExist(path)){
        int res = SD.remove(path);
        if (res == 0){
            Serial.println("ERREUR : Impossible d'effacer le fichier : " + path);
        }
    } else {
        Serial.println("ERREUR : le fichier " + path + " n'existe pas");
        return ERREUR_FILE_NOT_FOUND;
    }
    return NO_ERREUR;
}

int sdRmdir(String filename){
    String path = getPath(filename);
    if (fileExist(filename)){
        return SD.rmdir(filename);
    } else {
        Serial.println("ERREUR : le repertoire " + filename + " n'existe pas");
        return ERREUR_FILE_NOT_FOUND;
    }
    return NO_ERREUR;
}

int sdMkdir(String filename){
    String path = getPath(filename);
    int result = NO_ERREUR;
    if (! fileExist(path)){
        int res = SD.mkdir(path);
        if (res == 0){
            Serial.println("ERREUR : impossible de creer le repertoire " + path);
            result = ERREUR_CREATION_FILE;
        } else {
            result = NO_ERREUR;
        }
    } else {
        Serial.println("ERREUR : le repertoire " + path + " existe déjà");
        result = ERREUR_FILE_EXIST;
    }
    return result;
}

File sdPipeOpen(String filename){
    // creer repertoire /tmp/pipes s'il n'existe pas
    // creer un fichier pour ce pipe
    File fic;
    if ( ! SD.exists("/tmp")){
        SD.mkdir("/tmp/pipes)");
    }
    String path = "/tmp/pipes/" + filename;
    for (int i = 0 ; i < NB_PIPES ; i++){
        if (tblPipe[i].filename.length() == 0){
            fic = SD.open(path);
            tblPipe[i].filename=path;
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