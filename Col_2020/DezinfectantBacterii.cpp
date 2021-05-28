//
// Created by Robert on 28.05.2021.
//

#include "DezinfectantBacterii.h"

DezinfectantBacterii::DezinfectantBacterii(): Dezinfectant() {}

DezinfectantBacterii::DezinfectantBacterii(int nr_specii, const vector<string> &ingrediente, const vector<string> &suprafete)
: Dezinfectant(nr_specii, ingrediente, suprafete) {}

float DezinfectantBacterii::eficienta() {
    return (float)m_nr_specii / 1000000000;
}
