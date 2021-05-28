//
// Created by Robert on 28.05.2021.
//

#include "DezinfectantFungi.h"

DezinfectantFungi::DezinfectantFungi() : Dezinfectant(){}

DezinfectantFungi::DezinfectantFungi(int nr_specii, const vector<string> &ingrediente, const vector<string> &suprafete)
: Dezinfectant(nr_specii, ingrediente, suprafete) {}

float DezinfectantFungi::eficienta() {
    return (float)m_nr_specii / 1500000;
}
