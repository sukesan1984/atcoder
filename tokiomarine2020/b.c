#include <stdio.h>
#include <stdlib.h>

#define abs(a) (a) < 0 ? (-(a)) : (a)
int main() {
	long A;
	long V;
	long B;
	long W;
	long T;
	scanf("%ld", &A);
	scanf("%ld", &V);
	scanf("%ld", &B);
	scanf("%ld", &W);
	scanf("%ld", &T);
	long dif = abs(A - B);
	long sotai = V - W;
	if (sotai <= 0) {
		printf("NO\n");
		return 0;
	}

	long kyori = sotai * T;

	if (dif <= kyori)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
