#include "Reader.h"
#include "Writer.h"
#include <unordered_map>

int main() {
    std::vector<Triangle> triangles;
    std::vector<Point> uniquePoints;
    std::unordered_map<double, int> pointIndexMap; 

    Reader reader("cube-ascii.stl");
    reader.readTriangles(triangles, uniquePoints, pointIndexMap);

    // Write points and triangles to DAT file
    Writer writer("output.dat");
    writer.writePoints(uniquePoints);  // Writes the unique points
    writer.writeTriangles(triangles);   // Writes triangles with point indices

    return 0;
}
