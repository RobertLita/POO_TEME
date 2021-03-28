//
// Created by Robert on 17.03.2021.
//
#include "Desert.h"
#include "util.h"

Desert::Desert(char *tipd, short nrc):nr_cupe(nrc) {
    char *x=util::format(tipd);
    strcpy(tip_desert,x);
    if(strcmp(tip_desert,"Inghetata")==0){
        pret=nr_cupe*3;
    }
    else pret=15;
}

Desert::Desert():nr_cupe(0),pret(0){
    strcpy(tip_desert,"");
}

double Desert::get_pret() const {
    return pret;
}

std::ostream &operator<<(std::ostream &os, Desert &d) {
    os<<"   "<<d.tip_desert;
    if(strcmp(d.tip_desert,"Inghetata")==0)
    {
        os<<" "<<d.nr_cupe<<" cupe";
    }
    os<<": "<<d.pret<<'\n';
    return os;
}
