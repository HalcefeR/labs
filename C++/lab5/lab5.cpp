#include <iostream>
#include "vector_math_plus_1.h"


using namespace std;


int main(){

	int size, iter;
	bool is_plane = false; // is (size == 2) ?
	
	while (true){

		cout << "Enter the size of vectors (2 or 3): ";
		cin >> size;

		if (size == 0){
			cout << "End of the program..." << endl;
			break;
		}

		if ((size != 2) and (size != 3)){
			cout << "Uncorrect size! Try again" << endl;
			continue;
		}

		

		if (size == 2){
			is_plane = true;
		}

		float *vector1 = new float[3];
		float *vector2 = new float[3];
		float *vector_product = new float[3];

		cout << "Enter the elements of the first vector: ";
		for (iter = 0; iter < size; iter++){
			cin >> vector1[iter];
		}

		cout << "Enter the elements of the second vector: ";
		for (iter = 0; iter < size; iter++){
			cin >> vector2[iter];
		}

		if (is_plane){
			vector1[2] = 0;
			vector2[2] = 0;
		}

		vector_multiply(vector1, vector2, vector_product);

		cout << "Vector product: {" << vector_product[0] << ", " << vector_product[1] << ", " << vector_product[2] << "}" << endl;
		cout << "Parallelogram square: " << square_between_vectors(vector1, vector2) << endl;

		delete[] vector1;
		delete[] vector2;
		delete[] vector_product;

		cout << "________________________________" << endl << endl;
	}

	return 0;
}