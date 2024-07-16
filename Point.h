#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x, y, z;

public:
    // Constructor
    Point(int x = 0, int y = 0, int z = 0);

    // Translate function
    int translate(int d, char axis);

    // Display function
    void display() const;

    // Destructor
    ~Point();

    // Getters for the coordinates (needed for Triangle calculations)
    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }
};

#endif // POINT_H
