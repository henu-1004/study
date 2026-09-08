#include<stdio.h>

int f5(int n) {
	if (n < 10) {
		printf("!");
		return n + 3;
	}
	else
		return f5(n - 1) + 1;
}

int main() {
	int n;
	scanf_s("%d", &n);
	printf("%d", f5(n));


	return 0;
}