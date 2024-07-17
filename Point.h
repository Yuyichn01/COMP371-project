#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x, y, z;

public:
    // Constructor
    Point(int x = 0, int y = 0, int z = 0);

    // Get coordinate values
    int getX() const;
    int getY() const;
    int getZ() const;

    // Set coordinate values
    void setX(int x);
    void setY(int y);
    void setZ(int z);

    // Translation function
    int translate(int d, char axis);

    // Display the coordinates of a point
    void display() const;

    // Destructor
    ~Point();
};

#endif // POINT_H
