//---------------------------------------------------
//
//      commandes.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>


#ifndef __COMMANDES__
    #define __COMMANDES__

    #define NB_COMMANDES    17
    #define NB_PARAM 10

    extern String cdeTbl[NB_PARAM];
    typedef struct {
        String fluxin;
        String fluxout;
        String fluxerr;
    } struct_cde_flux;
    typedef  struct {
        struct_cde_flux cdeFlux;
        String commande;
    } struct_cde_data;

    extern struct_cde_flux main_cde_flux;
    extern struct_cde_data main_cde_data;

    extern int aide(struct_cde_data data);
    extern int cat(struct_cde_data data);
    extern int cd(struct_cde_data data);
    extern int cp(struct_cde_data data);
    extern int env(struct_cde_data data);
    extern int getAnalogPin(struct_cde_data data);
    extern int getDigitalPin(struct_cde_data data);
    extern int grep(struct_cde_data data);
    extern int mkdir(struct_cde_data data);
    extern int ls(struct_cde_data data);
    extern int pwd(struct_cde_data data);
    extern int rm(struct_cde_data data);
    extern int rmdir(struct_cde_data data);
    extern int set(struct_cde_data data);
    extern int setDigitalPin(struct_cde_data data);
    extern int unset(struct_cde_data data);
    extern int hystory(struct_cde_data data);

    // la liste des commandes et des fonctions assiciées 
    // est a renseigner dans le fichier commandes.cpp
    extern const String listeCommandes[NB_COMMANDES];
    extern int (*functptr[])(struct_cde_data);
    extern int nb_commandes;
    extern String prompt;

#endif
