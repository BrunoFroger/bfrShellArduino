//---------------------------------------------------
//
//      gestionFlux.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>

#include <SPI.h>
#include <SD.h>

#include "commandes.hpp"

void fluxFlush(String flux){
    if (flux.equals("fluxout")){
        Serial.flush();
    }
}

int fluxAvailable(String flux){
    if (flux.equals("fluxin")){
        return Serial.available();
    } else {
        Serial.println("le flux " + flux + " n'existe pas");
    }
    return 0;
}

char fluxRead(const String flux){
    if (flux.equals("fluxin")){
        // lecture sur flux d'entree standard
        if (Serial.available() > 0){
            return Serial.read();
        }
    } else {
        Serial.println("ERREUR : le flux " + flux + " n'est pas defini");
        return -1;
    }
    return -1;
}

void fluxWrite(const String flux, String data){
    if (flux.equals("fluxout")){
        // lecture sur flux de sortie standard
        Serial.print(data);
    } else if (flux.equals("fluxerr")){
        // lecture sur flux d'erreur standard
        Serial.print("ERREUR : " + data);
    } else {
        Serial.println("ERREUR : le flux " + flux + " n'est pas defini");
        return;
    }
}

void fluxWriteln(const String flux, String data){
    data += "\n";
    fluxWrite(flux, data);
}