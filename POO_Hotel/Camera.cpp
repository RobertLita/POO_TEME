//
// Created by Robert on 02.05.2021.
//

#include "Camera.h"

Camera::Camera():Incapere(2) {}

ostream &operator<<(ostream &os, const Camera &camera) {
    os<<"Camera "<< (const Incapere&) camera<<'\n';
    return os;
}



