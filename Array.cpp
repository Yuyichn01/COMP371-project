#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
	T* array;
	int size;

public:
	Array(int size) {
		while (size < 0) {
			cout << "Invalid Size. Enter size of array: ";
			cin >> size;
		}
		this->size = size;
		array = new T[this->size];
	}

	~Array() {
	        deleteArray();
    	}

	void initializeArray() {
		for (int i = 0; i < size; i++) {
			array[i] = T(i);
		}
	}

	void printArray() const{
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

	void resize(int newSize) {
		if (newSize < 0) {
			cout << "Invalid size. Size cannot be negative." << endl;
			return;
		}
	
		T* newArray = new T[newSize];
		int elementsToCopy = (newSize < size) ? newSize : size;
	
		for (int i = 0; i < elementsToCopy; i++) {
			newArray[i] = array[i];
		}
	
		deleteArray();
		array = newArray;
		size = newSize;
}
};

int main() {

	int size;
	cout << "Enter size of array: ";
	cin >> size;

	Array<int> array(size);
	array.initializeArray();
	array.printArray();

	int newSize;
	cout << "Enter new size of array: ";
	cin >> newSize;
	
	array.resize(newSize);
	array.printArray();
	
	array.deleteArray();
	array.printArray();
	
	return 0;
}
