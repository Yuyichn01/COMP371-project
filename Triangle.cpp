#include <iostream>
#include <cmath>

class Triangle {
private:
    Point *vertex_1, *vertex_2, *vertex_3;

public:
    // Constructor
    Triangle(Point *v1 = nullptr, Point *v2 = nullptr, Point *v3 = nullptr)
            : vertex_1(v1), vertex_2(v2), vertex_3(v3) {}

    // Translate function
    int translate(int d, char axis) {
        if (!vertex_1 || !vertex_2 || !vertex_3) return -1;
        vertex_1->translate(d, axis);
        vertex_2->translate(d, axis);
        vertex_3->translate(d, axis);
        return 0;
    }

    // Function to calculate the area of the triangle
    double calcArea() const {
        if (!vertex_1 || !vertex_2 || !vertex_3) return 0.0;

        // Using the formula: Area = 0.5 * | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) |
        int x1 = vertex_1->getX(), y1 = vertex_1->getY(), z1 = vertex_1->getZ();
        int x2 = vertex_2->getX(), y2 = vertex_2->getY(), z2 = vertex_2->getZ();
        int x3 = vertex_3->getX(), y3 = vertex_3->getY(), z3 = vertex_3->getZ();

        // Since we are in 3D space, using the cross product to find the area
        double area = 0.5 * std::abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
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
