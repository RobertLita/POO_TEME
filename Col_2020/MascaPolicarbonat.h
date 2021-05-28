//
// Created by Robert on 28.05.2021.
//

#ifndef COL_2020_MASCAPOLICARBONAT_H
#define COL_2020_MASCAPOLICARBONAT_H

#include "MascaChirurgicala.h"

class MascaPolicarbonat: public MascaChirurgicala{
private:
    string m_tip_prindere;
public:
    MascaPolicarbonat();
    explicit MascaPolicarbonat(const string& tip_prindere);
    void tip_masca(ostream& os) override;
    friend istream& operator>>(istream& is, MascaPolicarbonat &m);
    friend istream& operator>>(istream& is, MascaPolicarbonat *m);
    friend ostream& operator<<(ostream &os, MascaPolicarbonat &m);
    friend ostream& operator<<(ostream &os, MascaPolicarbonat *m);
};


#endif //COL_2020_MASCAPOLICARBONAT_H
