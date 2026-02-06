//----------------------------------------------
//
//      datas.hpp
//
//----------------------------------------------

#include <Arduino.h>
#ifndef __DATAS__
    #define __DATAS__

    #include "scheduler.hpp"

    #define NB_VARIABLES_ENV    100

    extern String listeVariablesEnv[NB_VARIABLES_ENV];
    extern String valeurVariablesEnv[NB_VARIABLES_ENV];

    extern String base_prompt;
    extern String prompt;

    extern scheduler mainTache;
    extern int getNewPid(void);

#endif