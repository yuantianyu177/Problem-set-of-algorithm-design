/* brute algorithm */
int FIND_MAX_SUBARRAY(int A[], int n) {
	int max = -100000;  
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++) {
				sum += A[k];
			}
			if (sum > max) {
				max = sum;
			}
			sum = 0;
		}
	}
	return max;
}
int main() {
	int a[16] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int re = FIND_MAX_SUBARRAY(a, 16);
	cout << re;
	return 0;
}