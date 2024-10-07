#ifndef READER_H
#define READER_H

#include <vector>
#include <unordered_map>
#include <fstream>
#include "Triangle.h"

class Reader {
public:
    explicit Reader(const std::string& filename);
    void readTriangles(std::vector<Triangle>& triangles, std::vector<Point>& uniquePoints, std::unordered_map<double, int>& pointIndexMap);
private:
    std::ifstream file;
};

#endif
