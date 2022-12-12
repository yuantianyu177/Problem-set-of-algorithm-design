/* Merge Sort */
void MERGE(int* A, int p, int q, int r) {
	int* re = new int[r - p + 1];
	int i = 0;
	int left = p;
	int right = q + 1;
	while (left != q + 1 && right != r + 1) {
		if (A[left] >= A[right]) {
			re[i] = A[right];
			right++;
			i++;
		}
		else {
			re[i] = A[left];
			left++;
			i++;
		}
	}
	if (left == q + 1) {
		while (i < r - p + 1) {
			re[i] = A[right++];
			i++;
		}
	}
	else {
		while (i < r - p + 1) {
			re[i] = A[left++];
			i++;
		}
	}
	for (int i = 0; i < r - p + 1; i++) {
		A[i + p] = re[i];
	}
}
void MERGE_SORT(int* A, int START, int END) {
	if (START < END) {
		int MIDDLE = (START + END) / 2;
		MERGE_SORT(A, START, MIDDLE);
		MERGE_SORT(A, MIDDLE + 1, END);
		MERGE(A, START, MIDDLE, END);
	}	
}