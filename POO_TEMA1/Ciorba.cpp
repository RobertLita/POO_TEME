//
// Created by Robert on 16.03.2021.
//

#include "Ciorba.h"
#include "util.h"
//functie care compara daca sirul a este egal cu b, indiferent de spatiile de la inceput, sau de literele mari/mici


Ciorba::Ciorba(char *numec, bool sm, bool ar): smantana(sm), ardei(ar) {
    char *x=util::format(numec);
    strcpy(nume,x);
    if(strcmp(nume,"Ciorba de legume")==0)
        pret_ciorba=10;
    else if(strcmp(nume,"Ciorba de burta")==0)
        pret_ciorba=15.5;
    else pret_ciorba = 12.2;
    if(smantana)pret_smantana=3.5;
    else pret_smantana=0;
    if(ardei)pret_ardei=1.5;
    else pret_ardei=0;
    pret_total=pret_ciorba+pret_smantana+pret_ardei;
}


Ciorba::Ciorba(): smantana(false), ardei(false), pret_ciorba(0),pret_ardei(0),pret_smantana(0),pret_total(0){
    strcpy(nume,"");
}

std::ostream &operator<<(std::ostream &os, Ciorba &c) {
    os<<"   "<<c.nume<<": "<<c.pret_ciorba<<'\n';
    if (c.smantana){
        os<<"   Smantana: "<<c.pret_smantana<<'\n';
    }
    if(c.ardei){
        os<<"   Ardei: "<<c.pret_ardei<<'\n';
    }
    return os;
}

double Ciorba::get_pret() const {
    return pret_total;
}
