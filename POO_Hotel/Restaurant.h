//
// Created by Robert on 04.05.2021.
//

#ifndef POO_HOTEL_RESTAURANT_H
#define POO_HOTEL_RESTAURANT_H

#include <ostream>
#include "Incapere.h"
class Restaurant: public Incapere{
private:
public:
    Restaurant();
    friend ostream &operator<<(ostream &os, const Restaurant &restaurant);
};


#endif //POO_HOTEL_RESTAURANT_H
