//
// Created by Robert on 17.03.2021.
//

#ifndef UNTITLED_DESERT_H
#define UNTITLED_DESERT_H
#include <cstring>
#include <iostream>

class Desert {
private:
    char tip_desert[10];
    short int nr_cupe;
    double pret;
public:
    explicit Desert(char tipd[],short int nrc=-1);
    Desert();
    double get_pret() const;
    friend std::ostream &operator<<(std::ostream &os,Desert &d);
};


#endif //UNTITLED_DESERT_H
