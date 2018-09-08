#pragma once

#define FLOATING_POINT_PRECISION_DOUBLE


#define EPSILON 0.0001

#ifdef FLOATING_POINT_PRECISION_DOUBLE
typedef double Float;
#else
typedef float Float;
#endif

#define PI 3.14159265358979
#define TWO_PI 6.28318530717958
#define PI_BY_TWO 1.57079632679489
#define PI_BY_FOUR 0.78539816339744
#define INV_PI 0.31830988618379
// Don't like this name...
#define NAT_LOG_E 2.71828182845904
