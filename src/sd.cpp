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

const int chipSelect = 10;
int sdOk;
File fic;
String repertoire = "/";

int sdInit(void){
    Serial.println("Initialisation de la carte SD...");

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
    return sdOk;
}

File sdOpen(String filename){
    fic = SD.open(filename);
    return fic;
}