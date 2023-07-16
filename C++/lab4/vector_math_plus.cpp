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

double length_of_vector(float *my_vector, int size){
	double scalar_square;

	scalar_square = scalar_product(my_vector, my_vector, size);

	return sqrt(scalar_square);
}

double angle_between_vectors(float *vector1, float *vector2, int size){
	double angle, my_cos;
	
	my_cos = scalar_product(vector1, vector2, size) / (length_of_vector(vector1, size) * length_of_vector(vector2, size));
	// rounding errors are possible!
	if (my_cos > 1){
		my_cos = 1;
	} else if (my_cos < -1) {
		my_cos = -1;
	}

	angle = acos(my_cos);

	return angle;
}