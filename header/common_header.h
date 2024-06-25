#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

#include "color.h"
#include "ray.h"
#include "vec3.h"

#endif