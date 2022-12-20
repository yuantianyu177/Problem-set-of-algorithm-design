/* Quick Sort */
int PARTITION(int* A, int i, int j) {
	int pivot = A[i];

	while (i < j) {
		while (A[j] >= pivot && i < j) {
			j--;
		}
		A[i] = A[j];
		while (A[i] <= pivot && i < j) {
			i++;
		}
		A[j] = A[i];
	}
	A[i] = pivot;
	return i;
}
void QUICK_SORT(int* A, int i, int j) {
	if (i < j) {
		int b = PARTITION(A, i, j);
		QUICK_SORT(A, 0, b - 1);
		QUICK_SORT(A, b + 1, j);
	}
}