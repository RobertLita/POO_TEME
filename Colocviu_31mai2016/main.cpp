#include <iostream>

#include "ComSpec.h"
#include "ComOnline.h"
#include "Ospatar.h"
#include "Restaurant.h"
int main() {
    Produs p1("frigarui",30);
    Produs p2("cola", 7.5);
    Produs p3("cafea", 5);
    Produs p4("frigarui de porc",35);
    Produs p5("frigarui de vita",38.5);
    Produs p6("papanasi", 20);
    Produs p7("papanasi cu nuca de cocos",25);
    Comanda c1("frigarui",2,30,5,2016);
    Comanda c2("cola",3), c3("cafea",1), c4=c2;
    Comanda c5;
    Comanda c6("papanasi",4);
    Comanda c7("cafea",6);
    c3 = c3 + 4;
    c2++;
    c1.del();
    //cin>>c5;
    cout<<c5<<'\n';
    Comanda *com1 = new Comanda[4], *com2 = new Comanda[4];
    com1[0] = c1; com1[1] = c2; com1[2] = c3;
    com2[0] = c4; com2[1] = c5;
    Ospatar o1("Ionescu", com1, 3, 'M', 25);
    Ospatar o2("Popescu", com2, 2, 'F', 30);
    cout<<o1<<'\n'<<o2<<'\n';
    if(o2 > o1) cout << "Ospatarul " << o2.nume() << " a servit mai multe comenzi decat ospatarul "<< o1.nume()<<'\n';
    else if (o1 == o2) cout<< "Numar egal de comenzi intre ospatarii " << o2.nume() << " si " << o1.nume() << '\n';
    else cout << "Ospatarul " << o2.nume() << " a servit mai putine comenzi decat ospatarul "<< o1.nume()<<'\n';
    ComSpec cs1(c1,"frigarui de porc",1);
    ComOnline co1(c6,"Strada Sperantei din Sesiune"), co2(c7,"Bulevardul Proiectelor din ultimele 2 saptamani");
    vector <Comanda*> comenzi_totale;
    comenzi_totale.push_back(&c1);
    comenzi_totale.push_back(&c2);
    comenzi_totale.push_back(&c3);
    comenzi_totale.push_back(&c4);
    comenzi_totale.push_back(&c5);
    comenzi_totale.push_back(reinterpret_cast<Comanda *const>(&co1));
    comenzi_totale.push_back(reinterpret_cast<Comanda *const>(&co2));
    vector <Ospatar*> ospatari;
    ospatari.push_back(&o1);
    ospatari.push_back(&o2);
    vector <Produs*> meniu;
    meniu.push_back(&p1);
    meniu.push_back(&p2);
    meniu.push_back(&p3);
    meniu.push_back(&p4);
    meniu.push_back(&p5);
    meniu.push_back(&p6);
    meniu.push_back(&p7);
    Restaurant X(comenzi_totale.size(), comenzi_totale, ospatari.size(), ospatari, meniu.size(), meniu);
    X.comenzi_la_data(19,5,2021);
    cout<<"La restaurant in luna mai 2021 s-au comandat " << X.nr_portii("cafea",5,2021) << " portii de cafea.\n";
    cout<<"Din totalul incasarilor din luna mai 2021, restaurantul a incasat "<< X.procent_online(5,2021) << "% din comenzile online.";
    return 0;
}
