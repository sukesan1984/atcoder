#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A;
	int B;
	scanf("%d", &A);
	scanf("%d", &B);
	int nyukokei = A + B;
	if (nyukokei >= 15 && B >= 8)
		printf("1\n");
	else if (nyukokei >= 10 && B >= 3)
		printf("2\n");
	else if (nyukokei >= 3)
		printf("3\n");
	else
		printf("4\n");
	return (0);
}
