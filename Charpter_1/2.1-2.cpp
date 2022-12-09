void INSERTION_SORT(int* array, int n) {
	int cur = 0;
	int index;
	for (int i = 1; i < n; i++) {
		cur = *(array + i);
		index = i - 1;
		while (index >= 0 && *(array + index) < cur) {
			*(array + index + 1) = *(array + index);
			index--;
		}
		*(array + index + 1) = cur;
	}
}