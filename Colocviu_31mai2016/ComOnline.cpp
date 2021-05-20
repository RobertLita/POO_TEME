//
// Created by Robert on 20.05.2021.
//

#include "ComOnline.h"

ComOnline::ComOnline(): adrLivrare("-"), comanda(), comLivrare(0) {}

ComOnline::ComOnline(Comanda &c, const string &adresa): adrLivrare(adresa), comanda(c) {
    comLivrare = c.getPret() / 20;
}

