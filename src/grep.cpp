//---------------------------------------------------
//
//      grep.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"
#include "commandes.hpp"
#include "sd.hpp"

void grepAide(void){
    Serial.println("Commande grep :");
    Serial.println("fonction : affiche la ligne si le terme pattern est inclu dans un fichier (chaines de caracteres uniquement)");
    Serial.println("usage    : grep <pattern> <nom fichier> ");
}

int grep(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        grepAide();
        return returnValue;
    } 
    String pattern = cdeTbl[1];
    String input = cdeTbl[2];
    if ((pattern.length() == 0) || (input.length() == 0)){
        Serial.println("grep : manque parametres");
        grepAide();
        return ERREUR_PARAMETRES;
    }
    // Serial.println("recherche de <" + pattern + "> dans le fichier <" + input + ">");
    File fichier;
    if (fileExist(input) == 1){
        fichier = sdOpenRead(input);
    } else {
        Serial.println("Erreur : le fichier <" + input + "> n'existe pas");
        return ERREUR_FILE_NOT_FOUND;
    }
    String result;
    int input_len = input.length() + 1;
    char input_array[input.length()];
    input.toCharArray(input_array, input_len);
    int pattern_len = pattern.length() + 1;
    char pattern_array[pattern_len];
    pattern.toCharArray(pattern_array, pattern_len);
    // if (strstr(input_array, pattern_array) != 0) {
    //     Serial.println(pattern);
    // }
    int numLigne = 1;
    while (fichier.available()){
        char ligne[256];
        //ligne = fichier.readString();
        for (int i = 0 ; i < 256 ; i++) ligne[i] = '\0';
        strcpy(ligne, "");
        fichier.readBytesUntil('\n', ligne, 256);
        // Serial.println("grep : Analyse de la ligne <" + String(ligne) + ">");
        // int ligne_len = pattern.length() + 1;
        // char ligne_array[input.length()];
        // ligne.toCharArray(ligne_array, ligne_len);
        if (strstr(ligne, pattern_array) > 0){
            Serial.println("ligne " + String(numLigne) + " : " + ligne);
        }
        numLigne++;
    }
    fichier.close();
    return returnValue;
}