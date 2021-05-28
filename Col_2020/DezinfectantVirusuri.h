//
// Created by Robert on 28.05.2021.
//

#ifndef COL_2020_DEZINFECTANTVIRUSURI_H
#define COL_2020_DEZINFECTANTVIRUSURI_H

#include "Dezinfectant.h"
class DezinfectantVirusuri: public Dezinfectant{
public:
    DezinfectantVirusuri();
    DezinfectantVirusuri(int nr_specii, const vector<string>& ingrediente, const vector<string>& suprafete);
    float eficienta() override;
};


#endif //COL_2020_DEZINFECTANTVIRUSURI_H
