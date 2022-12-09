/* The recursive form of Half to Find */
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