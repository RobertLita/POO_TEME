//
// Created by Robert on 04.05.2021.
//

#ifndef POO_HOTEL_SALA_H
#define POO_HOTEL_SALA_H
#include <string>
#include <ostream>
#include "Incapere.h"
using namespace std;
class Sala: public Incapere{
private:
    bool tipMese, areProiector, tipScena;
public:
    Sala();
    explicit Sala(const string& tip,bool proiector=false);
    friend ostream &operator<<(ostream &os, const Sala &sala);
};


#endif //POO_HOTEL_SALA_H
