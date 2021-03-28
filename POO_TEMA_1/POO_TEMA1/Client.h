//
// Created by Robert on 17.03.2021.
//
#ifndef UNTITLED_CLIENT_H
#define UNTITLED_CLIENT_H
#include "Ciorba.h"
#include "Fel_principal.h"
#include "Desert.h"
#include "Bautura.h"
#include <iostream>
using namespace std;

class Client {
private:
    static int id;
    Ciorba *c;
    Fel_principal *f;
    Desert *d;
    Bautura *b;
    double pret;
public:
    Client();
    Client(Ciorba *cc,Fel_principal *ff,Desert *dd,Bautura *bb);
    Client(Ciorba &cc,Fel_principal &ff,Desert &dd,Bautura &bb);
    Client(const Client &c);
    ~Client();
    void schimba_ciorba(Ciorba *cc);
    void schimba_ciorba(Ciorba &cc);
    void schimba_fel_principal(Fel_principal *ff);
    void schimba_fel_principal(Fel_principal &ff);
    void schimba_desert(Desert *dd);
    void schimba_desert(Desert &dd);
    void schimba_bautura(Bautura *bb);
    void schimba_bautura(Bautura &bb);
    friend ostream &operator<<(ostream &os,Client &nota);
};


#endif //UNTITLED_CLIENT_H
