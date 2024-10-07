#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
public:
    Point p1, p2, p3;  // Points that make up the triangle

    // Constructor that takes three Point objects
    Triangle(const Point& point1, const Point& point2, const Point& point3);
};

#endif
