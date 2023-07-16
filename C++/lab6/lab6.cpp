#include <iostream>
#include "matrix_operations.h"


using namespace std;


int main(){

	int m, n; // size of matrix
	int **matrix;
	int row; // iter
	int mode; // 1 or 2 - how to fill in matrix

	while (true){
		cout << "Enter the number of rows (m) and the number of columns (n): ";
		
		cin >> m;

		if (!m){
			cout << "End of program..." << endl;
			return 0;
		}
		cin >> n;

		if (!n){
			cout << "End of program..." << endl;
			return 0;
		}

		matrix = new int *[m];
		for (row = 0; row < m; row++){
			matrix[row] = new int[n];
		}
		
		mode = 0;
		while (!mode){
			cout << "Do you want to fill in the matrix yourself (1) or do it automatically(2)?" << endl;
			cin >> mode;
			if ((mode != 1) and (mode != 2)){
				cout << "Uncorrect input!" << endl;
				mode = 0;
			}
		}

		if (mode == 1){
			user_fills_matrix(matrix, m, n);
		} else {
			computer_fills_matrix(matrix, m, n);
		}

		cout << endl << "Matrix: " << endl;
		print_matrix(matrix, m, n);

		delete_max_row(&matrix, &m, n);
		delete_min_column(&matrix, m, &n);

		cout << "Matrix after row and column deletion: " << endl;
		print_matrix(matrix, m, n);

		if (m and n){
			cout << "The new size of matrix: " << m << "x" << n << endl;

			for(row = 0; row < m; row++){

				delete[] matrix[row];
			}

			delete[] matrix;
		}

		cout << "________________________________" << endl << endl;
	}

	return 0;
}

