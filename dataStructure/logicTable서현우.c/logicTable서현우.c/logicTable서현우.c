#include<stdio.h>
int main() {
	printf("과제 1\n");
	printf("p q (p & q) ~(p | q) (p & q) & ~(p | q)");
	int i, j, k;
	char p = 0, q = 0, r = 0, re1 = 0, re2 = 0, result = 0;
	for (i = 1; i >= 0; i--) {
		for (j = 1; j >= 0; j--) {
			if (i == 1)
				p = 'T';
			else if (i == 0)
				p = 'F';
			if (j == 1)
				q = 'T';
			else if (j == 0)
				q = 'F';
			if (i == 1 && j == 1)
				re1 = 'T';
			else if (i == 0 || j == 0)
				re1 = 'F';
			if (!i == 1 && !j == 1)
				re2 = 'T';
			else if (!i == 0 || !j == 0)
				re2 = 'F';
			if (re1 == 'T' && re2 == 'T')
				result = 'T';
			else if (re1 == 'F' || re2 == 'F')
				result = 'F';
			printf("\n%c %c    %c        %c            %c", p, q, re1, re2, result);
		}
	}
	printf("\n과제2\n");
	printf("p q r  (p->r)  (q->r)  (p->r) & (q->r)");
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
				if (!i == 1 || k == 1)
					re1 = 'T';
				else if (!i == 0 && k == 0)
					re1 = 'F';
				if (!j == 1 || k == 1)
					re2 = 'T';
				else if (!j == 0 && k == 0)
					re2 = 'F';
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