#include <iostream>

class Point {
private:
    int x, y, z;

public:
    // Constructor
    Point(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    // Translate function
    int translate(int d, char axis) {
        if (axis == 'x') {
            x += d;
        } else if (axis == 'y') {
            y += d;
        } else if (axis == 'z') {
            z += d;
        } else {
            return -1;
        }
        return 0;
    }

    // Display function
    void display() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")";
    }
};
