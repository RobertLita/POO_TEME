//
// Created by Robert on 16.03.2021.
//

#include "Masa.h"

int Masa::mese_totale;

Masa::Masa(int capacitate) {
    Masa::capacitate=capacitate;
    eOcupata=false;
    nr_persoane=0;
    mese_totale++;
    nr_masa=mese_totale;
}

void Masa::ocupa_masa(int nr_p) {
    if(!eOcupata && nr_persoane <= capacitate){
        eOcupata = true;
        nr_persoane = nr_p;
    }
}

void Masa::elibereaza_masa() {
    if(eOcupata) {
        eOcupata = false;
        nr_persoane = 0;
    }
    else {
        // TODO Stefan: sa ne permitem si glume :)), si rasete
        // TODO Robert: mi-a placut gluma, asa ca am lasat-o aici :DD
        cout << "Poate de praf s-o eliberezi, pt ca deja-i libera de clienti" << endl;
    }
}

std::ostream &operator<<(ostream &os, Masa m) {
    if(m.eOcupata){
        os<<"Masa "<<m.nr_masa<<" este ocupata de "<<m.nr_persoane<<" persoane\n";
    }
    else{
        os<<"Masa "<<m.nr_masa<<" este libera, avand o capacitate de "<<m.capacitate<<'\n';
    }
    return os;
}

