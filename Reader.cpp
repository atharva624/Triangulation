#include "Reader.h"
#include "Point.h"
#include "Triangle.h"
#include <fstream>      
#include <sstream>   
#include <string>    
#include <iostream>  
#include <unordered_map>

Reader::Reader(const std::string& filename) {
    file.open(filename, std::ios::in); 
}

void Reader::readTriangles(std::vector<Triangle>& triangles, std::vector<Point>& uniquePoints, std::unordered_map<double, int>& pointIndexMap) {
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    std::string line;
    Point p1, p2, p3;

    while (std::getline(file, line)) {
        if (line.find("vertex") != std::string::npos) {
            std::istringstream iss(line);
            std::string vertexKeyword;
            iss >> vertexKeyword >> p1.x >> p1.y >> p1.z;  

            
            std::getline(file, line);
            std::istringstream iss2(line);
            iss2 >> vertexKeyword >> p2.x >> p2.y >> p2.z; 

            std::getline(file, line);
            std::istringstream iss3(line);
            iss3 >> vertexKeyword >> p3.x >> p3.y >> p3.z; 

            
            for (const auto& point : { p1, p2, p3 }) {
                double coordinate = point.x * 1000000 + point.y * 1000 + point.z; 
                if (pointIndexMap.find(coordinate) == pointIndexMap.end()) {
                    pointIndexMap[coordinate] = static_cast<int>(uniquePoints.size());
                    uniquePoints.push_back(point);
                }
            }

            Triangle triangle(p1, p2, p3);
            triangles.push_back(triangle);
        }
    }
    file.close();
}
