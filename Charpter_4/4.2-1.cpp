/* Multiplication of matrices, Strassen algorithm */
int** my_malloc(int n) {
	int** A = new int* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}
	return A;
}

int** init(int* A[], int i, int j, int n) {
	int row, col;
	int** re = my_malloc(n / 2);
	if (i == 1 && j == 1) {
		row = 0;
		col = 0;
	}
	else if (i == 1 && j == 2) {
		row = 0;
		col = n / 2;
	}
	else if (i == 2 && j == 1) {
		row = n / 2;
		col = 0;
	}
	else {
		row = n / 2;
		col = n / 2;
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			*(re[i] + j) = *(A[row + i] + col + j);
		}
	}
	return re;
}

int** my_add(int* A[], int* B[], int n) {
	int** re = my_malloc(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(re[i] + j) = *(A[i] + j) + *(B[i] + j);
		}
	}
	return re;
}

int** my_minus(int* A[], int* B[], int n) {
	int** re = my_malloc(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(re[i] + j) = *(A[i] + j) - *(B[i] + j);
		}
	}
	return re;
}

int** matrix_plus(int** A, int** B, int n) {
	int** re = my_malloc(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(re[i] + j) = 0;
			for (int k = 0; k < n; k++) {
				*(re[i] + j) += (*(A[i] + k)) * (*(B[k] + j));
			}
		}
	}
	return re;
}

int** Strassen(int* A[], int* B[], int n) {
	int** A11 = init(A, 1, 1, n);
	int** A12 = init(A, 1, 2, n);
	int** A21 = init(A, 2, 1, n);
	int** A22 = init(A, 2, 2, n);
	int** B11 = init(B, 1, 1, n);
	int** B12 = init(B, 1, 2, n);
	int** B21 = init(B, 2, 1, n);
	int** B22 = init(B, 2, 2, n);

	int** S1 = my_minus(B12, B22, n / 2);
	int** S2 = my_add(A11, A12, n / 2);
	int** S3 = my_add(A21, A22, n / 2);
	int** S4 = my_minus(B21, B11, n / 2);
	int** S5 = my_add(A11, A22, n / 2);
	int** S6 = my_add(B11, B22, n / 2);
	int** S7 = my_minus(A12, A22, n / 2);
	int** S8 = my_add(B21, B22, n / 2);
	int** S9 = my_minus(A11, A21, n / 2);
	int** S10 = my_add(B11, B12, n / 2);

	int** P1 = matrix_plus(A11, S1, n / 2);
	int** P2 = matrix_plus(S2, B22, n / 2);
	int** P3 = matrix_plus(S3, B11, n / 2);
	int** P4 = matrix_plus(A22, S4, n / 2);
	int** P5 = matrix_plus(S5, S6, n / 2);
	int** P6 = matrix_plus(S7, S8, n / 2);
	int** P7 = matrix_plus(S9, S10, n / 2);

	int** C11 = my_add(my_minus(my_add(P5, P4, n / 2), P2, n / 2), P6, n / 2);
	int** C12 = my_add(P1, P2, n / 2);
	int** C21 = my_add(P3, P4, n / 2);
	int** C22 = my_minus(my_minus(my_add(P5, P1, n / 2), P3, n / 2), P7, n / 2);
	
	int** re = my_malloc(n);
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			*(re[i] + j) = *(C11[i] + j);
		}
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			*(re[i] + j + n / 2) = *(C12[i] + j);
		}
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			*(re[i + n / 2] + j) = *(C21[i] + j);
		}
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			*(re[i + n / 2] + j + n / 2) = *(C22[i] + j);
		}
	}

	return re;
}
int main() {
	int n = 4;
	int** A = my_malloc(n);
	int** B = my_malloc(n);
	A[0][0] = 1; A[0][1] = 2; A[0][2] = 3; A[0][3] = 4;
	A[1][0] = 2; A[1][1] = 3; A[1][2] = 4; A[1][3] = 5;
	A[2][0] = 3; A[2][1] = 4; A[2][2] = 5; A[2][3] = 6;
	A[3][0] = 5; A[3][1] = 6; A[3][2] = 7; A[3][3] = 8;

	B[0][0] = 4; B[0][1] = 3; B[0][2] = 2; B[0][3] = 1;
	B[1][0] = 5; B[1][1] = 4; B[1][2] = 3; B[1][3] = 2;
	B[2][0] = 6; B[2][1] = 5; B[2][2] = 4; B[2][3] = 3;
	B[3][0] = 7; B[3][1] = 6; B[3][2] = 5; B[3][3] = 4;

	int** re = Strassen(A, B, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << *(re[i] + j) << " ";
		}
		cout << "\n";
	}
	return 0;
}