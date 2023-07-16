#include <iostream>
#include <initializer_list>
#include "lab9.h"


using namespace std;


int main() {

	int size;
	int* pdata;

	CVector<int> first_vector{1, 1, 2, 3, 5, 8, 13, 21};
	cout << "The elements of the vector: ";
	for (int number : first_vector) {
		cout << number << ' ';
	}
	cout << endl;

	return 0;
}