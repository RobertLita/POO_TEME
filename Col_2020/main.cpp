#include <iostream>
#include "MascaPolicarbonat.h"
#include "DezinfectantBacterii.h"
#include "DezinfectantVirusuri.h"
#include "DezinfectantFungi.h"
#include "Achizitie.h"
using namespace std;
int main() {
    MascaChirurgicala mc1, mc2("ffp2", "verde brotacel", 55), mc3(mc1), mc4, mc5;
    mc4 = mc2;
    //cin >> mc5;
    cout << mc1 << mc2;
    MascaPolicarbonat* mp1=new MascaPolicarbonat(), * mp2=new MascaPolicarbonat();MascaPolicarbonat* mp3 = new MascaPolicarbonat("elastic");
    //cin >> mp1 >> mp2;
    cout << mp3;
    Dezinfectant* d1 = new DezinfectantBacterii(100000000,
                                                vector<string>({"sulfati non-ionici", "sulfati cationici", "parfumuri", "Linalool", "Metilpropanol butilpentil"}),
                                                vector<string>({"lemn, sticla, metal, ceramica, marmura"}));
    Dezinfectant* d2 = new DezinfectantVirusuri(50000000,
                                                vector<string>({"Alkil Dimetilm Benzil Crlorura de amoniu", "parfumuri", "Butilpentil metilpropinal"}),
                                                vector<string>({"lemn, sticla, ceramica, marmura"}));
    Dezinfectant* d3 = new DezinfectantFungi(1400000,
                                             std::vector<string>({"Alkil Etil Benzil Crlorura de amoniu", "parfumuri", "Butilpentil metilpropinal"}),
                                             vector<string>({"sticla, plastic"}));
    cout << d1->eficienta() << " " << d2->eficienta() << " " << d3->eficienta() << '\n';
    Achizitie* a1 = new Achizitie(26, 5, 2020, "PlushBio SRL");
    *a1 += mp1; //se adauga masca de policarbonat mp1 in lista de masti achizitionate
    *a1 += (&mc1); //se adauga masca chirugicala mc1 in lista
    *a1 += d3; // se adauga dezinfectantu de fungi d3 in lista de dezinfectanti achizitionati
    Achizitie* a2 = new Achizitie(25, 5, 2020, "Gucci");
    *a2 += d1;
    *a2 += d2;
    *a2 += d2;
    Achizitie a3, a4(*a1);
    a3 = *a2;
    if(*a1 < *a2) {
        cout << a1->nume() << " are valoarea facturii mai mica.\n";
    }else if (*a1 == *a2) {
        cout << a1->nume() << " si " << a2->nume() << "au aceasi valoare a facturii.\n";
    }
    else {
        cout << a2->nume() << " are valoarea facturii mai mica.\n";
        }
        return 0;
}
