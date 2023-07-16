#include <iostream>
#include <cmath>


using namespace std;


int solve_quadric(float a, float b, float c, double *x1, double *x2){
	double discriminant;

	discriminant = b*b - 4*a*c;
	if (discriminant < 0){
		return 0;
	}

	if ((x1 != nullptr) and (x2 != nullptr)){
		*x1 = (-b - sqrt(discriminant)) / (2*a);
		*x2 = (-b + sqrt(discriminant)) / (2*a);
	}
	if (discriminant == 0){
		return 1;
	}
	if (discriminant > 0){
		return 2;
	}
}
