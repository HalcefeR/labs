#include <iostream>
#include "vector_math.h"


using namespace std;


int main(){
	int size, iter;
	
	while (true){
		
		cout << "Enter the size of task: ";
		cin >> size;
		if (size < 0){
			cout << "Uncorrect input! Try again" << endl;
			continue;
		} 

		if (size == 0){
			cout << "End of the program..." << endl;
			break;
		}

		float *vector1 = new float[size];
		float *vector2 = new float[size];
		float *sum_of_vectors = new float[size];
		float *difference_of_vectors = new float[size];

		cout << "Enter the elements of the first vector: ";
		for (iter = 0; iter < size; iter++){
			cin >> vector1[iter];
		}

		cout << "Enter the elements of the second vector: ";
		for (iter = 0; iter < size; iter++){
			cin >> vector2[iter];
		}

		sum_vectors(vector1, vector2, sum_of_vectors, size);
		subtract_vectors(vector1, vector2, difference_of_vectors, size);

		cout << "Sum of vector1 and vector2: ( ";
		for (iter = 0; iter < size; iter++){
			cout << sum_of_vectors[iter] << " ";
		}
		cout << ")" << endl;

		cout << "Difference of vector1 and vector2: ( ";
		for (iter = 0; iter < size; iter++){
			cout << difference_of_vectors[iter] << " ";
		}
		cout << ")" << endl;

		cout << "Scalar product: " << scalar_product(vector1, vector2, size) << endl;

		delete[] vector1;
		delete[] vector2;
		delete[] sum_of_vectors;
		delete[] difference_of_vectors;

		cout << "________________________________" << endl << endl;
	}

	return 0;
} 
