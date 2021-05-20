//
// Created by Robert on 20.05.2021.
//

#ifndef COLOCVIU_31MAI2016_COMONLINE_H
#define COLOCVIU_31MAI2016_COMONLINE_H
#include "ComSpec.h"


class ComOnline {
private:
    string adrLivrare;
    int comLivrare;
    Comanda comanda;
public:
    ComOnline();
    explicit ComOnline(Comanda &c,const string& adresa);
};


#endif //COLOCVIU_31MAI2016_COMONLINE_H
