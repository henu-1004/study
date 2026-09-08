#include<stdio.h>
int main() {
	int test = 0;
	printf("Hello world\n");
	scanf_s(" %d", &test);
	printf("input value is %d \n", test);
	return 0;
}