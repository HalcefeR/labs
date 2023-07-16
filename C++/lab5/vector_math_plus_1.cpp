#include <iostream>
#include <cmath>


double scalar_product(float *vector1, float *vector2, int size){
	double scalar = 0;
	int iter;
	for (iter = 0; iter < size; iter++){
		scalar += vector1[iter] * vector2[iter];
	}
	return scalar;
}

void vector_multiply(float *v1, float *v2, float *vector_product){
	//			 |i     j     k    |
	// V1 x V2 = |v1[0] v1[1] v1[2]| = i * (v1[1]*v2[2] - v1[2]*v2[1]) - j * (v1[0]*v2[2] - v1[2]*v2[0]) + k * (v1[0]*v2[1] - v1[1]*v2[0])
	//			 |v2[0] v2[1] v2[2]|

	vector_product[0] = v1[1]*v2[2] - v1[2]*v2[1];
	vector_product[1] = -(v1[0]*v2[2] - v1[2]*v2[0]);
	vector_product[2] = v1[0]*v2[1] - v1[1]*v2[0];
}

double length_of_vector(float *my_vector, int size){
	double scalar_square;

	scalar_square = scalar_product(my_vector, my_vector, size);

	return sqrt(scalar_square);
}

double square_between_vectors(float *v1, float *v2){
	
	float *vector_product_1 = new float[3];
	double square;

	vector_multiply(v1, v2, vector_product_1);
	square = length_of_vector(vector_product_1, 3);
	delete[] vector_product_1;

	return square;
}
