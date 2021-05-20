//
// Created by Robert on 20.05.2021.
//

#include "ComSpec.h"

ComSpec::ComSpec(): Comanda() {}

ComSpec::ComSpec(const Comanda &c, const string &obs, int nr_portii): Comanda(c), ObsC(obs), nr_portii_spec(nr_portii){
    pretSupl = nr_portii_spec * (Produs::getPret(ObsC) - Produs::getPret(c.getProd().getDenProdus()));
}

float ComSpec::getPret() {
    return Comanda::getPret() + pretSupl;
}
