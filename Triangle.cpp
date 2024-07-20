#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

class Triangle {
private:
    Point *vertex_1, *vertex_2, *vertex_3;

public:
    // Constructor
    Triangle(Point *v1 = nullptr, Point *v2 = nullptr, Point *v3 = nullptr)
            : vertex_1(v1), vertex_2(v2), vertex_3(v3) {}

    // Translate function
    int shift(int d, char axis) {
        if (!vertex_1 || !vertex_2 || !vertex_3) return -1;
        vertex_1->translate(d, axis);
        vertex_2->translate(d, axis);
        vertex_3->translate(d, axis);
        return 0;
    }

    // Function to calculate the area of the triangle
    double calcArea() const {
        if (!vertex_1 || !vertex_2 || !vertex_3) return 0.0;

        // Get the coordinates of the vertices
        int x1 = vertex_1->getX(), y1 = vertex_1->getY(), z1 = vertex_1->getZ();
        int x2 = vertex_2->getX(), y2 = vertex_2->getY(), z2 = vertex_2->getZ();
        int x3 = vertex_3->getX(), y3 = vertex_3->getY(), z3 = vertex_3->getZ();

        // Vector AB (x2 - x1, y2 - y1, z2 - z1)
        int ABx = x2 - x1, ABy = y2 - y1, ABz = z2 - z1;
        // Vector AC (x3 - x1, y3 - y1, z3 - z1)
        int ACx = x3 - x1, ACy = y3 - y1, ACz = z3 - z1;

        // Cross product AB x AC
        int crossX = ABy * ACz - ABz * ACy;
        int crossY = ABz * ACx - ABx * ACz;
        int crossZ = ABx * ACy - ABy * ACx;

        // Area of the triangle is half the magnitude of the cross product
        double area = 0.5 * std::sqrt(crossX * crossX + crossY * crossY + crossZ * crossZ);
        return area;
    }

    // Display function
    void display() const {
        std::cout << "Triangle vertices:\n";
        vertex_1->display();
        std::cout << "\n";
        vertex_2->display();
        std::cout << "\n";
        vertex_3->display();
        std::cout << "\n";
    }

    // Destructor
    ~Triangle() {
        delete vertex_1;
        delete vertex_2;
        delete vertex_3;
    }
};
