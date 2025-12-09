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

        protected :
            // datas
            String prompt;
            // methodes
            void init();

    };

#endif