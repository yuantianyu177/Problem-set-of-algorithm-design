/*SUM_X complexity nlgn. give an integer set of n elements A and an integer x, 
find that if A contains 2 elements sum is x. */
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
int BINARY_SEARCH(int* A, int low, int high, int target) {
	if (low > high) {
		return -1;
	}
	int mid = (low + high) / 2;
	if (A[mid] == target) {
		return mid;
	}
	else if (A[mid] > target) {
		return BINARY_SEARCH(A, low, mid - 1, target);
	}
	else if (A[mid] < target) {
		return BINARY_SEARCH(A, mid + 1, high, target);
	}
}
bool SUM_X(int* A, int n, int x) {	
	MERGE_SORT(A, 0, n - 1);
	for (int i = 0; i < n; i++) {
		if (BINARY_SEARCH(A, 0, n - 1, x - A[i]) != -1 && x != 2 * A[i]) {
			return true;
		}
	}
	return false;
}
int main() {
	int a[10] = { 0,2,4,6,8,9,12,14,15,17 };
	bool index = SUM_X(a, 10, 33);
	cout << index;
	return 0;
}