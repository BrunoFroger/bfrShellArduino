//---------------------------------------------------
//
//      taches.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <iostream>

#include "gestionFlux.hpp"
#include "sd.hpp"
#include "commandes.hpp"

#ifndef __TACHE__
    #define __TACHE__

    #define MAX_PARAMETRES  10
    class tache {
        
        public:
            // methodes
            tache(struct_cde_flux flux, String commande);
            // int kill(void);
            int getPid(void);
            int exec(void);

        protected:
            // datas 
            int pid;
            String name;
            struct_cde_flux flux;
            String parametres[MAX_PARAMETRES];
            int (*functptr)(struct_cde_data);

            //methodes
            int init(struct_cde_flux flux, String parametres);
            void info(void);

    };

#endif