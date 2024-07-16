#include <iostream>

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
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    DynamicArray<int> arr;
    arr.add(1);
    arr.add(2);
    arr.add(3);
    arr.add(4);

    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr.get(i) << " "; // Print all elements in the array
    }
    std::cout << std::endl;

    arr.remove();
    arr.remove();

    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr.get(i) << " "; // Print remaining elements after removal
    }
    std::cout << std::endl;

    return 0;
}
