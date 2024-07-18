#include <iostream>
#include "Point.h"
#include "Triangle.h"

// Function to display the menu options
void menu() {
    std::cout << "Menu:\n";
    std::cout << "1. Create Triangle\n";
    std::cout << "2. Translate Triangle\n";
    std::cout << "3. Display Triangle\n";
    std::cout << "4. Calculate Area\n";
    std::cout << "5. Exit\n";
}

int main() {
    Point *p1 = nullptr, *p2 = nullptr, *p3 = nullptr;  // Pointers to Points for the vertices
    Triangle *triangle = nullptr;  // Pointer to the Triangle
    int choice, d;
    char axis;

    do {
        menu();  // Display the menu
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Create Triangle
                int x1, y1, z1, x2, y2, z2, x3, y3, z3;
                std::cout << "Enter coordinates of first point (x y z): ";
                std::cin >> x1 >> y1 >> z1;
                std::cout << "Enter coordinates of second point (x y z): ";
                std::cin >> x2 >> y2 >> z2;
                std::cout << "Enter coordinates of third point (x y z): ";
                std::cin >> x3 >> y3 >> z3;

                // Allocate memory for Points
                p1 = new Point(x1, y1, z1);
                p2 = new Point(x2, y2, z2);
                p3 = new Point(x3, y3, z3);

                // Allocate memory for Triangle with the Points
                triangle = new Triangle(p1, p2, p3);
                break;
            }
            case 2:
                // Translate Triangle
                std::cout << "Enter distance to translate: ";
                std::cin >> d;
                std::cout << "Enter axis (x, y, z): ";
                std::cin >> axis;
                if (triangle) {
                    triangle->translate(d, axis);  // Translate the Triangle if it exists
                } else {
                    std::cout << "No triangle created yet.\n";
                }
                break;

            case 3:
                // Display Triangle
                if (triangle) {
                    triangle->display();  // Display the Triangle if it exists
                } else {
                    std::cout << "No triangle created yet.\n";
                }
                break;

            case 4:
                // Calculate Area of Triangle
                if (triangle) {
                    std::cout << "Area of the triangle: " << triangle->calcArea() << "\n";
                } else {
                    std::cout << "No triangle created yet.\n";
                }
                break;

            case 5:
                // Exit
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    // Clean up dynamically allocated memory
    delete triangle;

    return 0;
}
