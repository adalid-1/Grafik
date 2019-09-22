//
// Created by adalid-1 on 9/19/19.
//

#ifndef GSCEPT_LAB_ENV_THING_H
#define GSCEPT_LAB_ENV_THING_H


#include "Ray.h"

struct hit_record{
    float t;
    Vector4D p;
    Vector4D normal;
};

class Shape {
public:
    virtual bool hit(const Ray& r, float tmin, float tmax, hit_record& rec) const = 0;
};


#endif //GSCEPT_LAB_ENV_THING_H
