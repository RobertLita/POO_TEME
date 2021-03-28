//
// Created by Robert on 16.03.2021.
//

#include "Fel_principal.h"
#include "util.h"


Fel_principal::Fel_principal(char numef[], char numeg[], char modg[], char tipv[], short int facut) {
    //chateaubriand
    char *x=util::format(numef);
    strcpy(nume_fel,x);
    if(strcmp(nume_fel,"Frigarui")==0){
        pret_fel=20.3;
    }
    else if(strcmp(nume_fel,"Tocana")==0)
        pret_fel=22.5;
    if(strcmp(numef,"Chateaubriand") == 0){
        facut_bine=facut;
        x=util::format(tipv);
        strcpy(tip_vita,x);
        pret_fel=35.9;
    }
    x=util::format(numeg);
    strcpy(nume_garnitura,x);
    if(strcmp(nume_garnitura,"Cartofi")==0){
        x=util::format(modg);
        strcpy(mod_garnitura,x);
        if(strcmp(mod_garnitura,"Prajiti")==0)
            pret_garnitura=8;
        else pret_garnitura=9.5;
    }
    else pret_garnitura=7.5;
    pret_total=pret_garnitura+pret_fel;
}

Fel_principal::Fel_principal(char numef[], char tipv[],short int facut) {
    char *x=util::format(numef);
    strcpy(nume_fel,x);//chateaubriand
    if(strcmp(nume_fel,"Chateaubriand") == 0){
        strcpy(tip_vita,tipv);
        facut_bine=facut;
        pret_fel=35.9;
    }
    else if(strcmp(nume_fel,"Frigarui")==0)
        pret_fel=20.3;
    else pret_fel=22.5;
    strcpy(nume_garnitura,"");
    pret_garnitura=0;
    pret_total=pret_fel+pret_garnitura;
}

Fel_principal::Fel_principal() :facut_bine(0),pret_fel(0),pret_garnitura(0),pret_total(0){
    strcpy(nume_fel,"");
    strcpy(tip_vita,"");
    strcpy(nume_garnitura,"");
    strcpy(mod_garnitura,"");
}

double Fel_principal::get_pret() const{
    return pret_total;
}

std::ostream &operator<<(std::ostream &os, Fel_principal &f) {
    os<<"   "<<f.nume_fel;
    if(strcmp(f.nume_fel,"Chateaubriand")==0)
        os<<' '<<f.tip_vita;
    os<<": "<<f.pret_fel<<'\n';
    if(strcmp(f.nume_garnitura,"")!=0)
    {
        os<<"   "<<f.nume_garnitura;
        if(strcmp(f.nume_garnitura,"Cartofi")==0)
            os<<' '<<f.mod_garnitura;
        os<<": "<<f.pret_garnitura<<'\n';
    }
    return os;
}