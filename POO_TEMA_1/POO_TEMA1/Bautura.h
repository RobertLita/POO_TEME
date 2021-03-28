//
// Created by Robert on 17.03.2021.
//

#ifndef UNTITLED_BAUTURA_H
#define UNTITLED_BAUTURA_H
#include "Ciorba.h"
#include <iostream>
#include <cstring>

class Bautura {
private:
    char tip_bautura[20],tip_vin[40];
    double cantitate;
    bool cuAlcool;
    double pret;
public:
    Bautura(char tipb[],char tipv[],double cant=1);//constructor pt vin
    Bautura(char tipb[],short int nrs=1,bool Alcool=false);//constructor pt bere si apa
    Bautura();
    double get_pret() const;
    friend std::ostream &operator<<(std::ostream &os,Bautura &b);
};


#endif //UNTITLED_BAUTURA_H
