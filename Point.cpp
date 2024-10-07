#include "Point.h"
#include <cmath>

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

bool Point::operator==(const Point& other) const {
    const double precision = 1e-6; // Precision for comparison
    return (std::fabs(x - other.x) < precision && std::fabs(y - other.y) < precision && std::fabs(z - other.z) < precision);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << std::fixed << std::setprecision(6) << point.x << " " << point.y << " " << point.z;
    return os;
}
