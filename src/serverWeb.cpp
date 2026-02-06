//----------------------------------------------
//
//      serverWeb.cpp
//
//----------------------------------------------

#include <Arduino.h>

#include <FS.h>
#include <LittleFS.h>
#include <SD.h>

#include "wifiTools.hpp"
#include "datas.hpp"
#include "scheduler.hpp"

// #define ACCES_SD    LittleFS
#define ACCES_SD    SDFS

int delaySendDatas=100;

//----------------------------------------------
//
//      initServerWeb
//
//----------------------------------------------
void initServerWeb(void){
    Serial.println("======================");
    Serial.println("|   Init Server Web  |");
    Serial.println("----------------------");
    Serial.println("initServerWeb => debut");
    
    //Begin LittleFS
    if (!LittleFS.begin())
    {
        Serial.println("An Error has occurred while mounting LittleFS");
        return;
    }
    Serial.println("LittleFS OK");
    Dir dir = LittleFS.openDir("/");
    Serial.println("Liste des fichiers en memoire flash :");
    while (dir.next()) {
        Serial.println(dir.fileName());
    }

    delay(100);

    //----------------------
    //
    // pages annexes
    //    
    //----------------------
    server.onNotFound([](AsyncWebServerRequest *request){ 
        Serial.println("requete /pageNotFound.html");
        //delay(delaySendDatas);
        // request->send(ACCES_SD, "pageNotFound.html", "text/html");
        request->send(LittleFS, "/pageNotFound.html", "text/html"); 
    });

    server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest * request){
        Serial.println("requete /favicon.ico");
        // request->send(ACCES_SD, "favicon.ico", "image/png");
        request->send(LittleFS, "/favicon.ico", "image/png");
    });

    server.on("/favicon.png", HTTP_GET, [](AsyncWebServerRequest * request){
        Serial.println("requete /favicon.png");
        // request->send(ACCES_SD, "favicon.png", "image/png");
        request->send(LittleFS, "/favicon.png", "image/png");
    });

    // server.on("/entete.html", HTTP_GET, [](AsyncWebServerRequest * request){
    //     Serial.println("requete /entete.html");
    //     //delay(delaySendDatas);
    //     request->send(SDFS, "/html/entete.html", "text/html");
    //     //request->send(LittleFS, "/html/entete.html", "text/html");
    // });

    server.on("/piedPage.html", HTTP_GET, [](AsyncWebServerRequest * request){
        Serial.println("requete /piedPage.html");
        //delay(delaySendDatas);
        // request->send(SDFS, "/html/piedPage.html", "text/html");
        request->send(LittleFS, "/piedPage.html", "text/html");
    });

    //----------------------
    //
    // feuilles de style
    //    
    //----------------------
    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest * request){
        // Serial.println("requete /style.css");
        // request->send(SDFS, "/html/style.css", "text/css");
        // String datas = "";
        // datas = lireFichier("/html/style.css");
        // request->send(200, "text/css", datas);});
        request->send(LittleFS, "/style.css", "text/css");   //Fichier en memoire flash
        // request->send(ACCES_SD, "style.css", "text/css");
    });

    //----------------------
    //
    // fichiers de scripts JS
    //    
    //----------------------

    server.on("/w3data.js", HTTP_GET, [](AsyncWebServerRequest * request){
        Serial.println("requete /w3data.js");
        // request->send(ACCES_SD, "w3data.js", "text/javascript");
        request->send(SDFS, "w3data.js", "text/javascript");
        // String datas = "";
        // datas = lireFichier("/html/w3data.js");
        // request->send(200, "text/javascript", datas);
    });

    server.on("/vue.global.js", HTTP_GET, [](AsyncWebServerRequest * request){
        Serial.println("requete /vue.global.js");
        // request->send(ACCES_SD,"vue.global.js", "text/javascript");
        request->send(SDFS,"vue.global.js", "text/javascript");
        // String datas = "";
        // datas = lireFichier("/html/vue.global.js");
        // request->send(200, "text/javascript", datas);
    });

    server.on("/scripts.js", HTTP_GET, [](AsyncWebServerRequest * request){
        Serial.println("requete /scripts.js");
        // request->send(ACCES_SD,"scripts.js", "text/javascript");
        request->send(LittleFS,"/scripts.js", "text/javascript");
        // request->send(SDFS,"scripts.js", "text/javascript");
        // String datas = "";
        // datas = lireFichier("/html/scripts.js");
        // delay(delaySendDatas);
        // request->send(200, "text/javascript", datas);
    });

    server.on("/main.js", HTTP_GET, [](AsyncWebServerRequest * request){
        Serial.println("requete /main.js");
        // request->send(SDFS,"main.js", "text/javascript");
        // request->send(ACCES_SD,"main.js", "text/javascript");
        request->send(LittleFS,"main.js", "text/javascript");
        // String datas = "";
        // datas = lireFichier("/html/main.js");
        // delay(delaySendDatas);
        // //Serial.println(datas);
        // request->send(200, "text/javascript", datas);
    });

    server.on("/bundle.js", HTTP_GET, [](AsyncWebServerRequest * request){
        Serial.println("requete /bundle.js");
        delay(delaySendDatas);
        // request->send(SDFS,"/html/bundle.js", "text/javascript");
        request->send(LittleFS, "/bundle.js", "text/javascript");   //Fichier en memoire flash
    });

    //----------------------
    //
    // pages fonctionnelles
    //    
    //----------------------

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){ 
        Serial.println("requete /");
        // request->send(SDFS, "/index.html", "text/html"); });
        // String datas = "";
        // datas = lireFichier("index.html");
        // delay(50);
        // request->send(200, "text/html", datas);});
        request->send(LittleFS,"/index.html", "text/html");
        // request->send(SDFS,"index.html", "text/html");
        //Serial.println("requete / traitée ...");
    });

    server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request){ 
        Serial.println("requete /index.html");
        // request->send(SDFS, "/index.html", "text/html"); });
        request->send(LittleFS,"/index.html", "text/html");
        // request->send(SDFS,"index.html", "text/html");
        // String datas = "";
        // datas = lireFichier("index.html");
        // delay(50);
        // request->send(200, "text/html", datas);
    });

    //----------------------
    //
    // requetes de modification de données
    //    
    //----------------------

    server.on("/sendCommande", HTTP_GET, [](AsyncWebServerRequest *request){ 
        String commande = request->getParam((size_t)0)->value();
        String pidString = request->getParam(1)->value();
        int pid = pidString.toInt();
        Serial.println("requete /sendCommande => pid = " + pidString + " ; commande = " + commande);
        request->send(200, "text/plain", "");
    });

    //----------------------
    //
    // requetes de recuperation de données
    //    
    //----------------------

    server.on("/getDatasConsole", HTTP_GET, [](AsyncWebServerRequest *request){ 
        Serial.println("requete /getDatasConsole");
        String reponse = "";
        // if (request->args() > 0){
            String pidString = request->getParam((size_t)0)->value();
            if (pidString.length() > 0) {
                int pid = pidString.toInt();
                reponse = "{\n";
                reponse += "\t\"consoleDatas\": \"" + mainTache.getDatasConsole(pid) + "\",\n";
                reponse += "\t\"status\": \"\",\n";
                reponse += "}";
            } else {
                reponse = "{\n";
                reponse += "\t\"consoleDatas\": \"\",\n";
                reponse += "\t\"status\": \"Erreur : Session pas initialisée\",\n";
                reponse += "}";
            }
        // }
        request->send(200, "text/json", reponse);
    });

    server.on("/initSession", HTTP_GET, [](AsyncWebServerRequest *request){ 
        Serial.println("requete /initSession");
        request->addInterestingHeader("Access-Control-Allow-Origin: *");
        request->addInterestingHeader("Access-Control-Allow-Origin: localhost");
        request->addInterestingHeader("Access-Control-Allow-Methods: GET, POST, PUT");
        request->addInterestingHeader("Access-Control-Allow-Headers: Content-Type");
        request->addInterestingHeader("Vary: Origin");
        String reponse = "";
        String commande = request->getParam((size_t)0)->value();
        String pidString = request->getParam((size_t)1)->value();
        reponse = "{\n";
        reponse += "\t\"pid\": \"" + pidString + "\",\n";
        reponse += "\t\"status\": \"\",\n";
        reponse += "\t\"console\": \"\",\n";
        reponse += "\t\"commande\": \"\",\n";
        reponse += "}";
        request->send(200, "text/json", reponse);
    });

    server.on("/sendCommande", HTTP_GET, [](AsyncWebServerRequest *request){ 
        Serial.println("requete /senCommande");
        String reponse = "";
        String pidString = String(mainTache.newMoniteur());
        reponse = "{\n";
        reponse += "\t\"pid\": \"" + pidString + "\",\n";
        reponse += "\t\"status\": \"\",\n";
        reponse += "\t\"console\": \"\",\n";
        reponse += "\t\"commande\": \"\",\n";
        reponse += "}";
        request->send(200, "text/json", reponse);
    });

    Serial.println("initServerWeb => fin");
}