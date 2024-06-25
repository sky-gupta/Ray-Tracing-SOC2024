#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
  public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;   //To know whether ray is inside or outside the spher

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.

        front_face = dot(r.direction(), outward_normal) < 0;    //if dot product is negatiive then its outside and normal is same as outward normal
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
  public:
    virtual ~hittable() = default;   //virtual allows runtime polymorphism and that derived class can make use of this overridden func

    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;  //=0 ensures that this base class doesn't has any implementation and is a pure virtual class
}; 

#endif