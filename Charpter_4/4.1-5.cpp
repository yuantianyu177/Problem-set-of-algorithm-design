int FIND_MAX_SUBARRAY(int A[], int n) {
	int max;
	int max_origin = A[0];
	int max_extend = A[0];
	int sum = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = j; k <= i; k++) {
				sum += A[k];
			}
			if (sum > max_extend) {
				max_extend = sum;
			}
			sum = 0;
		}
		max = max_origin > max_extend ? max_origin : max_extend;
		max_origin = max;
	}
	return max;
}
int main() {
	int a[16] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int re = FIND_MAX_SUBARRAY(a, 16);
	cout << re;
	return 0;
}