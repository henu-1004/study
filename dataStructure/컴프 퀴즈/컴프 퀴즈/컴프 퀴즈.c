#include<stdio.h>
int a, b, c;
void swap(void) {
	c = a;
	a = b;
	b = c;
}
int main() {
	printf("a 입력 : ");
	scanf_s("%d", &a);
	printf("b 입력 : ");
	scanf_s("%d", &b);
	swap();
	printf("a = %d\nb = %d", a, b);
	return 0;
}