//---------------------------------------------------
//
//      tache.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>

#include "gestionFlux.hpp"
#include "commandes.hpp"

#ifndef __TACHE__
#define __TACHE__

    #define MAX_PARAMETRES  10
    #define MAX_HISTORIQUE  10

    class tache{

        public:
            // methodes
            tache(struct_cde_flux flux, String parametres);
            // int kill(void);
            int getPid(void);
            String getDatasConsole(void);
            int exec(void);

        protected:
            // datas
            int pid;
            String commande;
            struct_cde_flux flux;
            String parametres[MAX_PARAMETRES];
            String historique[MAX_HISTORIQUE];
            int (*functptr)(struct_cde_data);
            String datasConsole;
            int priorite;
            int age;

            // methodes
            int init(struct_cde_flux flux, String parametres);
            void info(void);
    };

#endif