#include <iostream>
#include <random>
#include <ctime>


using namespace std;


void print_matrix(int **matrix, int m, int n){
	int row, col; // iters
	cout << endl;

	if (!m or !n){
		cout << "[DELETED]" << endl;
	} else {
		for (row = 0; row < m; row++){
			for (col = 0; col < n; col++){
				cout.setf(ios::left); // better output
				cout.width(4); // better output
				cout << matrix[row][col] << " ";
			}
			cout << endl;
		}
	}
	cout << endl;
}

void delete_max_row(int ***matrix, int *m, int n){
	int row, col; // iters
	int max_row;
	int sum, max_sum;

	max_sum = 0;
	max_row = 0;
	for (col = 0; col < n; col++){
		max_sum += (*matrix)[0][col];
	}
	
	for (row = 1; row < *m; row++){
		sum = 0;
		for (col = 0; col < n; col++){
			sum += (*matrix)[row][col];
		}
		
		if (sum > max_sum){
			max_sum = sum;
			max_row = row;
		}
	}
	
	for (row = max_row; row < (*m) - 1; row++){
		for (col = 0; col < n; col++){
			(*matrix)[row][col] = (*matrix)[row + 1][col];
		}
	}
	delete[] (*matrix)[(*m)];
	(*m)--;
}

void delete_min_column(int ***matrix, int m, int *n){
	int row, col; // iters
	int min_col;
	int sum, min_sum;

	min_sum = 0;
	min_col = 0;

	for (row = 0; row < m; row++){
		min_sum += (*matrix)[row][0];
	}
	
	for (col = 1; col < *n; col++){
		sum = 0;
		for (row = 0; row < m; row++){
			sum += (*matrix)[row][col];
		}

		if (sum < min_sum){
			min_sum = sum;
			min_col = col;
		}
	}
	
	for (col = min_col; col < (*n) - 1; col++){
		for (row = 0; row < m; row++){
			(*matrix)[row][col] = (*matrix)[row][col + 1];
		}
	}

	(*n)--;
}

void user_fills_matrix(int **matrix, int m, int n){
	short row, col; // iters

	cout << "Enter the elements of matrix ";
	cout << "(a_1_1, a_1_2, ... , a_" << m << "_" << n << "):" << endl;
	for (row = 0; row < m; row++){
		for (col = 0; col < n; col++){
			cin >> matrix[row][col];
		}
	}
}

void computer_fills_matrix(int **matrix, int m, int n){
	short row, col; // iters

	srand(time(NULL));
	for (row = 0; row < m; row++){
		for (col = 0; col < n; col++){
			matrix[row][col] = (rand() % 128) - 64;
		}
	}
}
