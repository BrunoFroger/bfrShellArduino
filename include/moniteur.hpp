//---------------------------------------------------
//
//      moniteur.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>
#include <iostream>
#include <string>


#ifndef __MONITEUR__
    #define __MONITEUR__

    class moniteur {

        public :
            moniteur();
            String getDatas();
            int getPid();

        protected :
            // datas
            String prompt;
            int pid;
            String dataConsole;
            // methodes
            void init();

    };

#endif