//
// Created by Robert on 16.03.2021.
//
#ifndef UNTITLED_FEL_PRINCIPAL_H
#define UNTITLED_FEL_PRINCIPAL_H
#include <iostream>
#include <cstring>

class Fel_principal {
private:
    char nume_fel[20],tip_vita[15];
    short int facut_bine;
    char nume_garnitura[20],mod_garnitura[20];
    double pret_fel,pret_garnitura,pret_total;
public:
    explicit Fel_principal(char numef[],char tipv[]=" ",short int facut=2);
    Fel_principal(char numef[],char numeg[], char modg[]="", char tipv[]="", short int facut=2);
    Fel_principal();
    friend std::ostream &operator<<(std::ostream &os,Fel_principal &f);
    double get_pret() const;
};


#endif //UNTITLED_FEL_PRINCIPAL_H
