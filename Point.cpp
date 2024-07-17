#include "Point.h"
#include <iostream>

// Constructor
Point::Point(int x, int y, int z) : x(x), y(y), z(z) {}

// Get coordinate values
int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

int Point::getZ() const {
    return z;
}

// Set coordinate values
void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::setZ(int z) {
    this->z = z;
}

// Translation function
int Point::translate(int d, char axis) {
    if (axis != 'x' && axis != 'y' && axis != 'z') {
        return -1; // Invalid axis
    }
    if (d != static_cast<int>(d)) {
        return -2; // Invalid distance
    }

    switch (axis) {
        case 'x':
            x += d;
            break;
        case 'y':
            y += d;
            break;
        case 'z':
            z += d;
            break;
    }
    return 0; // Successful
}

// Display the coordinates of a point
void Point::display() const {
    std::cout << "Point(" << x << ", " << y << ", " << z << ")" << std::endl;
}

// Destructor
Point::~Point() {
    
}
