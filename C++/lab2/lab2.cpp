#include <iostream>
#include "solves.h"

using namespace std;


int main(){
	float a, b, c; // parameters
	double x1 = 0, x2 = 0; // roots
	int number_of_roots;

	while (true){
		cout << "Enter a, b, c: " << endl;
		cin >> a;
		if (a < 0.0001){
			cout << "End of the program..." << endl;
			return 0;
		}
		cin >> b >> c;

		number_of_roots = solve_quadric(a, b, c, &x1, &x2); 
		cout << "Number of roots: " << number_of_roots << endl;
		if (number_of_roots and (((x1 != 0) and (x2 != 0)) or ((b == 0) and (c == 0)))){
			cout << "x1: " << x1 << endl;
			cout << "x2: " << x2 << endl;	
		}
		cout << "________________________________" << endl << endl;
	}
	return 0;
} 
