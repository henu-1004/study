#include<stdio.h>
int IsPrimeNumber(int n) {
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0) return 0;
	return 1;
}
int main() {
	for (int j = 2; j <= 100; j++) {
		if (IsPrimeNumber(j)) printf("%d ", j);
		else printf("_ ");
	}
	return 0;
}