//
// Created by Robert on 28.05.2021.
//

#include "DezinfectantVirusuri.h"

DezinfectantVirusuri::DezinfectantVirusuri() : Dezinfectant() {}

DezinfectantVirusuri::DezinfectantVirusuri(int nr_specii, const vector<string> &ingrediente, const vector<string> &suprafete)
: Dezinfectant(nr_specii, ingrediente, suprafete) {}

float DezinfectantVirusuri::eficienta() {
    return (float)m_nr_specii / 100000000;
}
