//
// Created by Robert on 04.05.2021.
//

#include "Restaurant.h"

Restaurant::Restaurant(): Incapere(100) {}

ostream &operator<<(ostream &os, const Restaurant &restaurant) {
    os << "Restaurant cu numarul "<<restaurant.m_id_incapere<<'.';
    return os;
}
