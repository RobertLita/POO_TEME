//
// Created by Robert on 02.05.2021.
//

#ifndef POO_HOTEL_CAMERA_H
#define POO_HOTEL_CAMERA_H

#include "Incapere.h"

class Camera: public Incapere {
private:
public:
    Camera();
    friend ostream &operator<<(ostream &os, const Camera& camera);

};


#endif //POO_HOTEL_CAMERA_H
