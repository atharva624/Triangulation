#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <iomanip>

class Point {
public:
    double x, y, z;

    Point(double x = 0, double y = 0, double z = 0);

    bool operator==(const Point& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

#endif 
