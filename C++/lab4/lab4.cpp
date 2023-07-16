#include <iostream>
#include "vector_math_plus.h"


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

		if (!size){
			cout << "End of the program..." << endl;
			break;
		}

		float *vector1 = new float[size];
		float *vector2 = new float[size];

		cout << "Enter the elements of the first vector: ";
		for (iter = 0; iter < size; iter++){
			cin >> vector1[iter];
		}

		cout << "Enter the elements of the second vector: ";
		for (iter = 0; iter < size; iter++){
			cin >> vector2[iter];
		}

		cout << "Length of the first vector: " << length_of_vector(vector1, size) << endl;
		cout << "Length of the second vector: " << length_of_vector(vector2, size) << endl;
		cout << "Angle between vectors (rad): " << angle_between_vectors(vector1, vector2, size) << endl;

		delete[] vector1;
		delete[] vector2;

		cout << "________________________________" << endl << endl;
	}

	return 0;
}