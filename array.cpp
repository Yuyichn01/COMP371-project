#include <iostream>
using namespace std;

template <typename T>
T* createArray(int size) {
	T* array = new T[size];
	return array;
}

template <typename T>
void initializeArray(T* array,  int size) {
	for (int i = 0; i < size; i++) {
		array[i] = T(i);
	}
}

template <typename T>
void printArray(T* array, int size) {
	cout << "[";
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			cout << array[i];
		} 
		else
			cout << array[i] << ", ";
	}
	cout << "]";
}

template <typename T>
void deleteArray(T* array) {
	// TO BE IMPLEMENTED
}

int main() {

	int size;
	cout << "Enter size of array: ";
	cin >> size;

	int* array = createArray<int>(size);
	initializeArray(array, size);
	printArray(array, size);
	deleteArray(array);
}
