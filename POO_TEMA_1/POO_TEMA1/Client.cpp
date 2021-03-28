//
// Created by Robert on 17.03.2021.
//

#include "Client.h"

int Client::id;

Client::Client():c(nullptr),f(nullptr),d(nullptr),b(nullptr),pret(0){
}

Client::Client(Ciorba *cc, Fel_principal *ff, Desert *dd, Bautura *bb): pret(0){
    id++;
    c=new Ciorba(*cc);
    pret+=c->get_pret();
    f=new Fel_principal(*ff);
    pret+=f->get_pret();
    d=new Desert(*dd);
    pret+=d->get_pret();
    b=new Bautura(*bb);
    pret+=b->get_pret();
}

Client::~Client() {
    id--;
    if(c != nullptr)
    {
        delete c;
    }
    if(f != nullptr)
    {
        delete f;
    }
    if(d != nullptr)
    {
        delete d;
    }
    if(b != nullptr)
    {
        delete b;
    }
}

void Client::schimba_ciorba(Ciorba *cc) {
    if (c != nullptr) {
        pret-=c->get_pret();
        c = new Ciorba(*cc);
        pret+=c->get_pret();
    } else {
        cout << "Nu ai comandat nicio ciorba" << '\n';
    }
}

void Client::schimba_fel_principal(Fel_principal *ff) {
    if (f != nullptr) {
        pret-=f->get_pret();
        f = new Fel_principal(*ff);
        pret+=f->get_pret();
    } else {
        cout << "Nu ai comandat niciun fel principal" << '\n';
    }
}

void Client::schimba_desert(Desert *dd) {
    if (d != nullptr) {
        pret-=d->get_pret();
        d = new Desert(*dd);
        pret+=d->get_pret();
    } else {
        cout << "Nu ai comandat niciun desert" << '\n';
    }
}

void Client::schimba_bautura(Bautura *bb) {
    if (b != nullptr) {
        pret-=b->get_pret();
        b = new Bautura(*bb);
        pret+=b->get_pret();
    } else {
        cout << "Nu ai comandat nicio bautura" << '\n';
    }
}

Client::Client(Ciorba &cc, Fel_principal &ff, Desert &dd, Bautura &bb) {
    Client(&cc,&ff,&dd,&bb);
}

void Client::schimba_bautura(Bautura &bb) {
    this->schimba_bautura(&bb);
}

void Client::schimba_fel_principal(Fel_principal &ff) {
    this->schimba_fel_principal(&ff);
}

void Client::schimba_ciorba(Ciorba &cc) {
    this->schimba_ciorba(&cc);
}

ostream &operator<<(ostream &os, Client &nota) {
    cout<<"Clientul "<<nota.id<<":\n";
    cout<<*nota.c<<*nota.f<<*nota.d<<*nota.b;
    os <<"_______________________" <<"\nTotal de plata: "<< nota.pret <<"\n\n";
    return os;
}

void Client::schimba_desert(Desert &dd) {
    this->schimba_desert(&dd);
}

Client::Client(const Client &clold) {
    id++;
    c=new Ciorba(*clold.c);
    pret+=c->get_pret();
    f=new Fel_principal(*clold.f);
    pret+=f->get_pret();
    d=new Desert(*clold.d);
    pret+=d->get_pret();
    b=new Bautura(*clold.b);
    pret+=b->get_pret();
}
