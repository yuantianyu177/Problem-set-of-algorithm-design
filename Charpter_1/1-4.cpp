/* Add n bits of binary numbers */
int* ADD_BINARY(int* A, int* B, int n) {
	int* re = new int[n + 1];
	int carry = 0;
	for (int i = n - 1; i >= 0; i--) {
		*(re + i + 1) = *(A + i) + *(B + i) + carry;
		if (*(re + i + 1) == 2) {
			carry = 1;
			*(re + i + 1) = 0;
		}
		else if (*(re + i + 1) == 3) {
			carry = 1;
			*(re + i + 1) = 1;
		}
		else {
			carry = 0;
		}
	}
	*re = (carry == 1) ? 1 : 0;
	return re;
}