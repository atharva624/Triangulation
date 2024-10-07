#ifndef WRITER_H
#define WRITER_H

#include <fstream>
#include <vector>
#include "Triangle.h"

class Writer {
public:
    Writer(const std::string& filename);
    void writePoints(const std::vector<Point>& points);
    void writeTriangles(const std::vector<Triangle>& triangles);

private:
    std::ofstream file;
};

#endif // WRITER_H
