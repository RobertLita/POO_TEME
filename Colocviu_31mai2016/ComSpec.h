//
// Created by Robert on 20.05.2021.
//

#ifndef COLOCVIU_31MAI2016_COMSPEC_H
#define COLOCVIU_31MAI2016_COMSPEC_H

#include "Comanda.h"
class ComSpec: public Comanda{
private:
    int nr_portii_spec;
    string ObsC;
    float pretSupl;
public:
    ComSpec();
    ComSpec(const Comanda &c, const string &obs, int nr_portii);
    float getPret() override;
};


#endif //COLOCVIU_31MAI2016_COMSPEC_H
