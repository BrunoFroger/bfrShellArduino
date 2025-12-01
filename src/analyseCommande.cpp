//---------------------------------------------------
//
//      analyseCommande.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "erreurs.hpp"
#include "commandes.hpp"
#include "analyseCommande.hpp"
#include "gestionFlux.hpp"

String cdeTbl[NB_PARAM];
String listeCdes[NB_PARAM];
String listeCdesPipes[NB_PARAM];

void decomposeCommande(String data, char separateur, String listeDatas[]){

    const int maxTokens = 10; // Nombre maximum d'éléments dans le tableau
    String tokens[maxTokens];
    int tokenCount = 0;

    unsigned int startIndex = 0;
    while (data.indexOf(" ", startIndex) == 0 ) startIndex++;
    int commaIndex;

    while ((commaIndex = data.indexOf(separateur, startIndex)) != -1 && tokenCount < maxTokens) {
        listeDatas[tokenCount++] = data.substring(startIndex, commaIndex);
        startIndex = commaIndex + 1;
    }
    // Ajouter le dernier token après la dernière virgule
    if (startIndex < data.length() && tokenCount < maxTokens) {
        listeDatas[tokenCount++] = data.substring(startIndex);
    }

    // Afficher les tokens
    // for (int i = 0; i < tokenCount; i++) {
        // Serial.println(cdeTbl[i]);
    // }
}

int executeCommande(String commande){
    int returnValue = NO_ERREUR;
    // String buffer;
    for (int i = 0 ; i < NB_PARAM ; i++){
        cdeTbl[i]="";
    }
    // buffer = "Analyse de la commande <" + commande + ">";
    // Serial.println(buffer);
    // Serial.println("Analyse de la commande <" + commande + ">");
    // decomposeCommande(commande, '|', listeCdes);
    decomposeCommande(commande, ' ', cdeTbl);
    int i;
    if (!cdeTbl[0].equals("")){
        for (i=0 ; i < NB_COMMANDES ; i++){
            if (cdeTbl[0] == listeCommandes[i]){
                returnValue=(*functptr[i])(commande);
                // Serial.println("Fin de la cde : " + cdeTbl[0] + " ; res = " + String(returnValue));
                break;
            }
        }
        if (i >= NB_COMMANDES) {
            fluxWriteln("fluxerr", "commande inconnue : " + commande);
            returnValue = ERREUR_COMMANDE_INCONNUE;
        }
    }

    return returnValue;
}

int analyseCommande(String commande){
    // decomposition des commmandes en pipes
    String commandesRestantes = commande;
    String commandeATraiter;
    boolean fin = false;
    int result = NO_ERREUR;
    while (! fin){
        int index = commandesRestantes.indexOf("|");
        // Serial.println("| detecte en posiiton " + String(index));
        if (index == -1) fin = true;
        commandeATraiter = commandesRestantes.substring(0,index);
        // Serial.println("execution de la commande <" + commandeATraiter + ">");
        result = executeCommande(commandeATraiter);
        if (result != NO_ERREUR) return result;
        String newCommande = commandesRestantes.substring(index + 1);
        commandesRestantes = newCommande;
    }
    return result;
}