//
// Created by Robert on 28.05.2021.
//

#include "Dezinfectant.h"

Dezinfectant::Dezinfectant():m_nr_specii(0), m_ingrediente(), m_suprafete() {}

Dezinfectant::Dezinfectant(int nr_specii, const vector<string> &ingrediente, const vector<string> &suprafete): m_nr_specii(nr_specii), m_suprafete(suprafete), m_ingrediente(ingrediente) {}

float Dezinfectant::eficienta() {
    return 0;
}
