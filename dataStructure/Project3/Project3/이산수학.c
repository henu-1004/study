#include<stdio.h>
int main() {
	printf("과제 1\n");
	printf("p q (p & q) ~(p | q) (p & q) & ~(p | q)");
	int i, j, k;
	char p = 0, q = 0, r = 0, re1 = 0, re2 = 0, result = 0;
	for (i = 1; i >= 0; i--) {
		for (j = 1; j >= 0; j--) {
			if (i == 1)
				printf("%c", 'T');
			else if (i == 0)
				printf("%c", 'F');
			if (j == 1)
				printf("%c", 'T');
			else if (j == 0)
				printf("%c", 'F');
			if (i == 1 && j == 1)
				printf("%c", 'T');
			else if (i == 0 || j == 0)
				printf("%c", 'F');
			if (!i == 1 && !j == 1)
				printf("%c", 'T');
			else if (!i == 0 || !j == 0)
				printf("%c", 'F');
			if (re1 == 'T' && re2 == 'T')
				printf("%c", 'T');
			else if (re1 == 'F' || re2 == 'F')
				printf("%c", 'F');
		}
		return 0;
	}
	printf("\n과제2\n");
	printf("p q r  (p->r)  (q->r)  (p->q) & (q->r)");
	for (i = 1; i >= 0; i--) {
		for (j = 1; j >= 0; j--) {
			for (k = 1; k >= 0; k--) {
				if (i == 1)
					p = 'T';
				else if (i == 0)
					p = 'F';
				if (j == 1)
					q = 'T';
				else if (j == 0)
					q = 'F';
				if (k == 1)
					r = 'T';
				else if (k == 0)
					r = 'F';
				if (i == 1 && k == 1)
					re1 = 'T';
				else if (i == 1 && k == 0)
					re1 = 'F';
				else if (i == 0)
					re1 = 'T';
				if (j == 1 && k == 1)
					re2 = 'T';
				else if (j == 1 && k == 0)
					re2 = 'F';
				else if (j == 0)
					re2 = 'T';
				if (re1 == 'T' && re2 == 'T')
					result = 'T';
				else if (re1 == 'F' || re2 == 'F')
					result = 'F';
				printf("\n%c %c %c    %c        %c          %c", p, q, r, re1, re2, result);
			}
		}
	}



	return 0;
}