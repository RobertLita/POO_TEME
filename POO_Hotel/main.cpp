#include "Hotel.h"
using namespace std;
int main() {
    //Cred ca m-am complicat putin, dar pana la urma a iesit cu voiam
    Persoana p1("Popescu","Ion","camera","restaurant");
    //se rezerva camera 2 pt persoana p1

    Persoana p2("Mickey","Mouse","apartament","camera");
    //se rezerva apartamentul 3 pt persoana p2

    Persoana p3("Ionescu","Eugen","camera","camera");
    //persoana p3 se cazeaza in camera cu p1, deoarece mai este loc

    Persoana p4("Peter","Parker","apartament","restaurnat");
    Persoana p5("Bob","Ross","apartament","camera");
    //persoanele p4 si p5 se cazeaza in apartament cu p2, deocarece mai este loc

    Persoana p6("Arhimede","din Siracuza","camera","restaurant");
    //persoala p6 se cazeaza intr-o noua camera, deoarece inca camera 2 nu mai este loc

    Sala s1("scena",true);
    Sala s2("mese");
    //grupul doreste si o sala cu scena si proiector

    vector<Persoana> p;
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);
    p.push_back(p6);

    Grup g1(6,1,12,7,p,true,s1);
    //grupul format din 6 persoane se cazeaza pe 1 dec, sta 7 zile si doreste o sala cu scena si proiector

    Hotel Hotel_California;
    Hotel_California.cazeazaGrup(g1);
    //grupul g1 se cazeaza

    //cout<<Hotel_California<<'\n';
    //afisam incaperile din hotel
    //cout<<g1;
    //afisam informatii despre grup
    Persoana p7("Fluviul","Dunarea","apartament","restaurant");
    Persoana p8("Andreea","Esca","camera","camera");
    Persoana p9("Michael","Jackson","camera","camera");
    Persoana p10("Popescu","Teodor","apartament","restaurant");
    p.clear();
    p.push_back(p7);
    p.push_back(p8);
    p.push_back(p9);
    p.push_back(p10);

    Grup g2(4,20,4,10,p,true,s2);
    Hotel_California.cazeazaGrup(g2);

        //Hotel_California.anuleazaRezervare(g1);
        //In hotel raman doar cei din grupul g2
        //Hotel_California.anuleazaRezervare(g2);
    cout<<Hotel_California;
    return 0;
}
