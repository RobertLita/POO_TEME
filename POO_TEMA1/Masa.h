//
// Created by Robert on 16.03.2021.
//

#ifndef UNTITLED_MASA_H
#define UNTITLED_MASA_H
#include <iostream>
using namespace std;

class Masa {
private:
    static int mese_totale;
    int nr_masa;
    int capacitate;
    int nr_persoane;
    bool eOcupata;
public:
    explicit Masa(int capacitate);
    void ocupa_masa(int nr_persoane);
    void elibereaza_masa();
    friend std::ostream &operator<<(std::ostream &os,Masa m);
};


#endif //UNTITLED_MASA_H
