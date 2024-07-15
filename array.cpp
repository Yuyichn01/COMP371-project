#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
	T* array;
	int size;

public:
	Array(int size) {
		this->size = size;
		array = new T[size];
	}

	~Array() {
	        if (array != nullptr)
            		delete[] array;
    	}

	void initializeArray() {
		for (int i = 0; i < size; i++) {
			array[i] = T(i);
		}
	}

	void printArray() {
		if (array == nullptr) {
            		cout << "Array is empty or has been deleted.\n";
            		return;
        	}
		cout << "[";
		for (int i = 0; i < size; i++) {
			if (i == size - 1) {
				cout << array[i];
			}
			else
				cout << array[i] << ", ";
		}
		cout << "]\n";
	}

	void deleteArray() {
		if (array != nullptr) {
            		delete[] array;
            		array = nullptr;
            		size = 0;
        	}
	}

	T getElement(int index) const {
		if (index >= 0 && index < size) {
			return array[index];
		}
		else {
			cout << "Invalid index.\n";
			return T();
		}
	}

	void setElement(int index, T value) {
		if (index >= 0 && index < size) {
			array[index] = value;
		}
		else {
			cout << "Invalid index.\n";
		}
	}
};

int main() {

	int size;
	cout << "Enter size of array: ";
	cin >> size;

	Array<int> array(size);
	array.initializeArray();
	array.printArray();
	array.deleteArray();
	array.printArray();
	
	return 0;
}
