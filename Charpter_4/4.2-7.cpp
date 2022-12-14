/* Multiply 3 times to compute complex numbers */
int* complex(int a, int b, int c, int d) {
	int prod1 = a * c;
	int prod2 = b * d;
	int prod3 = (a + b) * (c + d);
	int* re = new int[2];
	re[0] = prod1 - prod2;
	re[1] = prod3 - prod1 - prod2;
	return re;
}

int main() {
	int* re = complex(1, 2, 3, 4);
	cout << re[0] << " " << re[1];
	return 0;
}