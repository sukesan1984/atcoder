#include <stdio.h>

int main()
{
	int A;
	int B;
	int C;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	if (A * A + B * B < C * C)
		printf("Yes\n");
	else
		printf("No\n");
	return (0);
}
