/* heap sort */
void MIN_HEAPIFY(int* A, int i, int size) {
	int temp;
	while (i * 2 <= size) {
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
			i = min;
		}
		else {
			i++;
		}
	}
	return;
}

void HEAP_SORT(int* A, int size) {
	for (int i = size / 2; i > 0; i--) {
		MIN_HEAPIFY(A, i, size);
	}

	int temp;
	for (int i = size; i > 1; i--) {
		temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		MIN_HEAPIFY(A, 1, i - 1);
	}
}