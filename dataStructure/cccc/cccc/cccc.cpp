#include<stdio.h>
#include<string.h>
//#pragma warning(disable:4996);

int main() {
	char str[5000] = { "" };
	printf("문자열 입력(엔터만 입력시 종료)");
	fgets(str, sizeof(str), stdin);
	while (1) {
		if (strlen(str) == 1 && str[0] == '\n') {
			printf("프로그램 종료");
			break;
		}
		else {
			printf("계산함");
			//계산 진행하고 출력도 다하고
			fgets(str, sizeof(str), stdin);
		}

	}

	return 0;
}