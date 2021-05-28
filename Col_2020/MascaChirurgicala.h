//
// Created by Robert on 28.05.2021.
//

#ifndef COL_2020_MASCACHIRURGICALA_H
#define COL_2020_MASCACHIRURGICALA_H

#include <string>
#include <iostream>
using namespace std;
class MascaChirurgicala {
protected:
    int m_nr_pliuri;
    string m_culoare, m_tip_protectie;
public:
    MascaChirurgicala();
    MascaChirurgicala(const string& tip_protectie, const string& culoare, int nr_pliuri);
    friend istream& operator>>(istream& is, MascaChirurgicala& m);
    friend ostream& operator<<(ostream &os, MascaChirurgicala& m);
    virtual void tip_masca(ostream &os);
    const string &getTipProtectie() const;
};


#endif //COL_2020_MASCACHIRURGICALA_H
