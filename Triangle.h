#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    Point *vertex_1, *vertex_2, *vertex_3;

public:
    // Constructor
    Triangle(Point *v1 = nullptr, Point *v2 = nullptr, Point *v3 = nullptr);

    // Translate function
    int translate(int d, char axis);

    // Function to calculate the area of the triangle
    double calcArea() const;

    // Display function
    void display() const;

    // Destructor
    ~Triangle();
};

#endif // TRIANGLE_H
