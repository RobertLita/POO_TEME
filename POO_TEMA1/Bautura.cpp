//
// Created by Robert on 17.03.2021.
//
#include "Bautura.h"
#include "util.h"

Bautura::Bautura(char *tipb, short nrs, bool Alcool):cantitate(nrs),cuAlcool(Alcool) {
    char *x=util::format(tipb);
    strcpy(tip_bautura,x);
    if(strcmp(tipb,"Sticla bere")==0)pret=cantitate*7;
    else pret=cantitate*3;
}

Bautura::Bautura(char *tipb, char *tipv, double cant):cuAlcool(true) {
    char *x=util::format(tipb);
    strcpy(tip_bautura,x);
    x=util::format(tipv);
    strcpy(tip_vin,x);
    cantitate=cant;
    if(strcmp(tip_bautura,"Vin varsat")==0) {
        if (strcmp(tip_bautura, "Rosu") == 0)
            pret = cantitate * 7.5 / 100;
        else pret= cantitate * 7 / 100;
    }
    else pret=cantitate*90;
}

Bautura::Bautura(): cuAlcool(false),cantitate(0),pret(0) {
    strcpy(tip_bautura,"");
}

double Bautura::get_pret() const {
    return pret;
}

std::ostream &operator<<(std::ostream &os, Bautura &b) {
    os<<"   ";
    if(strcmp(b.tip_bautura,"Vin varsat")==0)
        os<<b.tip_bautura<<' '<<b.tip_vin<<' '<<b.cantitate<<"ml";
    else if(strcmp(b.tip_bautura,"Sticla vin")==0)
       os << b.cantitate << "x " << b.tip_bautura << ' ' << b.tip_vin;
    else os << b.cantitate << "x " << b.tip_bautura;
    os<<": "<<b.pret<<'\n';
    return os;
}
