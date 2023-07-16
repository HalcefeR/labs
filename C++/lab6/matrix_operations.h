#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

void print_matrix(int **matrix, int m, int n);
void delete_max_row(int ***matrix, int *m, int n);
void delete_min_column(int ***matrix, int m, int *n);
void user_fills_matrix(int **matrix, int m, int n);
void computer_fills_matrix(int **matrix, int m, int n);

#endif