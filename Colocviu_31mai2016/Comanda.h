//
// Created by Robert on 19.05.2021.
//

#ifndef COLOCVIU_31MAI2016_COMANDA_H
#define COLOCVIU_31MAI2016_COMANDA_H

#include <ostream>
#include "Produs.h"

class Comanda {
protected:
    int nrPortii;
    static int Num;
    int nr_comanda;
    Produs Prod;
    struct Data{
        int zi, luna, an;
        Data(): zi(0),luna(0), an(0){};
        Data(int Zi, int Luna, int An): zi(Zi), luna(Luna), an(An){};
    }data;
public:
    Comanda();
    Comanda(const string& p, int portii, int zi=0, int luna=0 , int an=0);
    Comanda& operator+(int x);
    Comanda& operator++();
    Comanda operator++(int);
    friend istream& operator>>(istream& is, Comanda& c);
    friend ostream &operator<<(ostream &os, const Comanda &comanda);
    void del();
    virtual float getPret();
    const Produs &getProd() const;
    int getNrPortii() const;
    const Data &getData() const;
};


#endif //COLOCVIU_31MAI2016_COMANDA_H
