//
// Created by Robert on 28.05.2021.
//

#ifndef COL_2020_DEZINFECTANTBACTERII_H
#define COL_2020_DEZINFECTANTBACTERII_H

#include "Dezinfectant.h"
class DezinfectantBacterii: public Dezinfectant {
public:
    DezinfectantBacterii();
    DezinfectantBacterii(int nr_specii, const vector<string>& ingrediente, const vector<string>& suprafete);
    float eficienta() override;
};


#endif //COL_2020_DEZINFECTANTBACTERII_H
