void sum_vectors(float vector1[], float vector2[], float sum_of_vectors[], int size){
	int iter;
	for (iter = 0; iter < size; iter++){
		sum_of_vectors[iter] = vector1[iter] + vector2[iter];
	}
}

void subtract_vectors(float vector1[], float vector2[], float difference_of_vectors[], int size){
	int iter;
	for (iter = 0; iter < size; iter++){
		difference_of_vectors[iter] = vector1[iter] - vector2[iter];
	}
}

double scalar_product(float vector1[], float vector2[], int size){
	double scalar = 0;
	int iter;
	for (iter = 0; iter < size; iter++){
		scalar += vector1[iter] * vector2[iter];
	}
	return scalar;
} 
