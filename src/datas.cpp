//----------------------------------------------
//
//      datas.cpp
//
//----------------------------------------------

#include <Arduino.h>

#include "datas.hpp"

String base_prompt = "SD_Shell : ";
String prompt = base_prompt;

String listeVariablesEnv[NB_VARIABLES_ENV];
String valeurVariablesEnv[NB_VARIABLES_ENV];