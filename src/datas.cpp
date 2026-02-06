//----------------------------------------------
//
//      datas.cpp
//
//----------------------------------------------

#include <Arduino.h>

#include "datas.hpp"
#include "scheduler.hpp"

String base_prompt = "SD_Shell : ";
String prompt = base_prompt;
int newPid = 0;

String listeVariablesEnv[NB_VARIABLES_ENV];
String valeurVariablesEnv[NB_VARIABLES_ENV];

scheduler mainTache;

int getNewPid(void){
    return ++newPid;
}