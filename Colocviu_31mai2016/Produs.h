//
// Created by Robert on 19.05.2021.
//

#ifndef COLOCVIU_31MAI2016_PRODUS_H
#define COLOCVIU_31MAI2016_PRODUS_H

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Produs {
private:
    static unordered_map<string, float> preturi;
    string denProdus;
    float pretProdus;
public:
    Produs();
    explicit Produs(const string& produs, float pret=0);
    static float getPret(const string& produs);
    const string &getDenProdus() const;
    friend ostream &operator<<(ostream &os, const Produs &produs);

};


#endif //COLOCVIU_31MAI2016_PRODUS_H
