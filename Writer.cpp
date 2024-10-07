#include "Writer.h"
#include <iomanip>  // For setting precision

Writer::Writer(const std::string& filename) {
    file.open(filename, std::ios::out);
}

void Writer::writePoints(const std::vector<Point>& points) {
    for (const Point& point : points) {
        file << std::fixed << std::setprecision(6)  // Optional: Set precision for floating-point numbers
            << point.x << " " << point.y << " " << point.z << std::endl;
    }
}

void Writer::writeTriangles(const std::vector<Triangle>& triangles) {
    for (const Triangle& triangle : triangles) {
        // Write the coordinates of each point (p1, p2, p3) of the triangle
        file << std::fixed << std::setprecision(6)  // Optional: Set precision for floating-point numbers
            << triangle.p1.x << " " << triangle.p1.y << " " << triangle.p1.z << std::endl
            << triangle.p2.x << " " << triangle.p2.y << " " << triangle.p2.z << std::endl
            << triangle.p3.x << " " << triangle.p3.y << " " << triangle.p3.z << std::endl;
    }

    file << "EOF" << std::endl;  // End of file marker
    file.close();
}
