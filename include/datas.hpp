//----------------------------------------------
//
//      datas.hpp
//
//----------------------------------------------

#include <Arduino.h>
#ifndef __DATAS__
    #define __DATAS__

    #define NB_VARIABLES_ENV    100

    extern String listeVariablesEnv[NB_VARIABLES_ENV];
    extern String valeurVariablesEnv[NB_VARIABLES_ENV];

    extern String base_prompt;
    extern String prompt;

#endif