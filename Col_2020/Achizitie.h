//
// Created by Robert on 28.05.2021.
//

#ifndef COL_2020_ACHIZITIE_H
#define COL_2020_ACHIZITIE_H

#include "MascaPolicarbonat.h"
#include "Dezinfectant.h"
class Achizitie {
private:
    struct data{
        int zi, luna, an;
        data(): zi(0), luna(0), an(0){}
        data(int z, int l, int a): zi(z), luna(l), an(a) {}
    }m_data;
    int m_nr_masti, m_nr_dezinfectanti;
    string m_nume;
    Dezinfectant* m_dezinfectanti;
    MascaChirurgicala* m_masti;
    int m_pret;
public:
    Achizitie();
    Achizitie(int zi, int luna, int an, const string& nume);
    Achizitie(const Achizitie &a);
    ~Achizitie();
    Achizitie& operator=(Achizitie& a);
    Achizitie& operator+=(const MascaChirurgicala& m);
    Achizitie& operator+=(const MascaChirurgicala* m);
    Achizitie& operator+=(const Dezinfectant* d);
    bool operator<(const Achizitie &a) const;
    bool operator==(const Achizitie &a) const;
    const string &nume() const;
};


#endif //COL_2020_ACHIZITIE_H
