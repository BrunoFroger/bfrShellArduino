//---------------------------------------------------
//
//      scheduler.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <iostream>

#include "gestionFlux.hpp"
#include "sd.hpp"
#include "commandes.hpp"
#include "tache.hpp"

#ifndef __SCHEDULER__
    #define __SCHEDULER__

    #define MAX_TACHES      20
    
    class scheduler {
        
        public:
            // methodes
            scheduler();
            int kill(int pid);
            String getDatasConsole(int pid);
            int newMoniteur(void);
            int executeCommande(int pid, String commande);

        protected:
            // datas 
            tache *listeTaches[MAX_TACHES];
            
            //methodes
            int init(void);
            void info(void);

    };

#endif