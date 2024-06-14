#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
  public:
    ray() {}

    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    const point3& origin() const  { return orig; }
    const vec3& direction() const { return dir; }

    point3 at(double t) const {
        return orig + t*dir;
    }

    double distance_to_point(const point3& point) const {   //Additional utility to calculate distance of a point to ray
        vec3 oc = point - orig;
        double t = dot(dir,oc) / dot(dir,dir);
        if (t < 0) t = 0; // Clamp t to zero to handle points behind the origin
        point3 closest_point = at(t);
        return (point - closest_point).length();
    }

  private:
    point3 orig;
    vec3 dir;
};
#endif
