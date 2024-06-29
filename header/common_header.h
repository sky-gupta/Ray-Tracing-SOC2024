#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>
#include <interval.h>
#include <algorithm>

using std::make_shared;
using std::shared_ptr;
using std::sqrt;
using std::fabs;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    return min + (max-min)*random_double();
}

#include "color.h"
#include "ray.h"
#include "vec3.h"

#endif