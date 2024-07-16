#include <iostream>
using namespace std;

/*
 This is an implementation of amortized dynamic arrayThis method expands and contracts the array based on its usage.
 The array's capacity is doubled when it is full and halved when the number of elements is less than a quarter of the capacity.
 This method ensures that the array does not use excessive memory.
 */

// Template class for a dynamic array with amortized doubling and halving
template <typename T>
class DynamicArray {
private:
    T* array; // Pointer to the array
    size_t size; // Current number of elements in the array
    size_t capacity; // Maximum number of elements the array can hold before needing to resize

    // Private method to resize the array to a new capacity
    void resize(size_t newCapacity) {
        T* newArray = new T[newCapacity]; // Allocate a new array with the new capacity
        for (size_t i = 0; i < size; ++i) {
            newArray[i] = array[i]; // Copy elements to the new array
        }
        delete[] array; // Free the old array
        array = newArray; // Update the array pointer to the new array
        capacity = newCapacity; // Update the capacity
    }

public:
    // Constructor to initialize the array with an initial capacity
    DynamicArray(size_t initialCapacity = 4) : size(0), capacity(initialCapacity) {
        array = new T[capacity];
    }

    // Destructor to free the allocated memory
    ~DynamicArray() {
        delete[] array;
    }

    // Method to add an element to the array
    void add(const T& element) {
        if (size == capacity) {
            resize(capacity * 2); // Resize the array if it is full (double the capacity)
        }
        array[size++] = element; // Add the element and increment the size
    }

    // Method to remove the last element from the array
    void remove() {
        if (size == 0) return;
        size--; // Decrement the size
        if (size < capacity / 4) {
            resize(capacity / 2); // Resize the array if it is less than a quarter full (halve the capacity)
        }
    }

    // Method to get an element at a specific index
    T get(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index]; // Return the element at the given index
    }

    // Method to get the current size of the array
    size_t getSize() const {
        return size;
    }

    // Method to get the current capacity of the array
    size_t getCapacity() const {
        return capacity;
    }
};

// Main function to test the DynamicArray class
int main() {
    size_t initialCapacity, numberOfElements;
    int element;

    std::cout << "Enter the initial capacity of the array: ";
    std::cin >> initialCapacity;

    DynamicArray<int> arr(initialCapacity);

    std::cout << "Enter the number of elements to add: ";
    std::cin >> numberOfElements;

    for (size_t i = 0; i < numberOfElements; ++i) {
        std::cout << "Enter element " << (i + 1) << ": ";
        std::cin >> element;
        arr.add(element);
    }

    std::cout << "Array elements after adding:" << std::endl;
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr.get(i) << " "; // Print all elements in the array
    }
    std::cout << std::endl;

    size_t numberOfRemovals;
    std::cout << "Enter the number of elements to remove: ";
    std::cin >> numberOfRemovals;

    for (size_t i = 0; i < numberOfRemovals; ++i) {
        arr.remove();
    }

    std::cout << "Array elements after removing:" << std::endl;
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr.get(i) << " "; // Print the remaining elements in the array after removal
    }
    std::cout << std::endl;

    std::cout << "Current array size: " << arr.getSize() << std::endl; // Print the current size of the array
    std::cout << "Current array capacity: " << arr.getCapacity() << std::endl; // Print the current capacity of the array

    return 0;
}
