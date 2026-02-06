//---------------------------------------------------
//
//      flux.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>
#include <iostream>
#include <SPI.h>
#include <SD.h>

#ifndef __FLUX__
    #define __FLUX__

    class flux {
        public:
            flux();
            ~flux();
            char read();
            void write(String);
            void writeln(String);

        protected:
            String name;
            File *fluxin;
            File *fluxout;
            File *fluxerr;
    }

#endif