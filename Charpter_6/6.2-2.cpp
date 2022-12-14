void MIN_HEAPIFY(int* A, int i, int size) {
	if (i * 2 > size) {
		return;
	}
	int temp;
	int min = i;
	int left = 2 * i;
	int right = 2 * i + 1;
	if (left <= size && A[left] < A[i]) {
		min = left;
	}
	if (right <= size && A[right] < A[min]) {
		min = right;
	}
	if (min != i) {
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
	MIN_HEAPIFY(A, min, size);
}