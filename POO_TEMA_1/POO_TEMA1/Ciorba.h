//
// Created by Robert on 16.03.2021.
//

#ifndef UNTITLED_CIORBA_H
#define UNTITLED_CIORBA_H
#include <iostream>
#include <cstring>
class Ciorba {
private:
    char nume[20];
    bool smantana,ardei;
    double pret_ciorba,pret_smantana,pret_ardei,pret_total;
public:
    Ciorba(char *nume,bool smantana,bool ardei);
    Ciorba();
    double get_pret() const;
    friend std::ostream &operator<<(std::ostream &os,Ciorba &m);
};


#endif //UNTITLED_CIORBA_H
