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
		delete[] array;
	}

	void initializeArray() {
		for (int i = 0; i < size; i++) {
			array[i] = T(i);
		}
	}

	void printArray() {
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
};

int main() {

	int size;
	cout << "Enter size of array: ";
	cin >> size;

	Array<int> array(size);
	array.initializeArray();
	array.printArray();

	return 0;
}
