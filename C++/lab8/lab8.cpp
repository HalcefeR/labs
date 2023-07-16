#include <iostream>
#include "lab8.h"


using namespace std;


int main() {

	int size;
	int* pdata;

	while (true) {
		cout << "Enter the size of the vector: ";
		cin >> size;
		if (size <= 0) break;
		pdata = new int[size];
		cout << "Enter the elements of the vector: " << endl;
		for (int i = 0; i < size; i++) {
			cin >> pdata[i];
		}
		CVector<int> first_vector(size, pdata);
		delete[] pdata;
		
		cout << "The elements of the vector (for): ";
		for (auto iter = first_vector.begin(); iter != first_vector.end(); ++iter) {
			cout << *iter << ' ';
		}
		cout << endl;
		cout << "The elements of the vector (range for): ";
		for (int number : first_vector) {
			cout << number << ' ';
		}
		cout << endl;

	}

	return 0;
}