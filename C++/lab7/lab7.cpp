#include <iostream>
#include "lab7.h"


using namespace std;


int main() {

	int size;
	double* pdata;

	while (true) {
		cout << "Enter the size of the first vector: ";
		cin >> size;
		if (size <= 0) break;
		pdata = new double[size];
		cout << "Enter the elements of the first vector: " << endl;
		for (int i = 0; i < size; i++) {
			cin >> pdata[i];
		}
		CVector<double> first_vector(size, pdata);
		delete[] pdata;
		first_vector.print_data();

		cout << "Enter the size of the second vector: ";
		cin >> size;
		if (size <= 0) break;
		pdata = new double[size];
		cout << "Enter the elements of the second vector: " << endl;
		for (int i = 0; i < size; i++) {
			cin >> pdata[i];
		}
		CVector<double> second_vector(size, pdata);
		delete[] pdata;
		cout << "Elements of the second vector: ";
		second_vector.print_data();
		
		CVector<double> temp_vector;

		temp_vector = first_vector + second_vector;
		cout << "Sum of vectors: " << endl;
		temp_vector.print_data();
		temp_vector = first_vector - second_vector;
		cout << "Difference of vectors: " << endl;
		temp_vector.print_data();

		double s_product; 
		s_product = first_vector * second_vector;
		cout << "Scalar product of vectors: " << endl;
		cout << s_product << endl;

		cout << "Absolute value of the first vector: " << endl;
		cout << first_vector() << endl;
	}

	return 0;
}