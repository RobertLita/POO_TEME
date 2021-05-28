//
// Created by Robert on 28.05.2021.
//

#ifndef COL_2020_DEZINFECTANT_H
#define COL_2020_DEZINFECTANT_H

#include <vector>
#include <string>
using namespace std;
class Dezinfectant {
protected:
    int m_nr_specii;
    vector<string> m_ingrediente, m_suprafete;
public:
    Dezinfectant();
    Dezinfectant(int nr_specii, const vector<string>& ingrediente, const vector<string>& suprafete);
    virtual float eficienta();
};


#endif //COL_2020_DEZINFECTANT_H
