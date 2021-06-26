#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A, B, C;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	if (A >= B && B >= C)
	{
		printf("%d", A + B);
	}
	else if (A >= C && C >= B)
	{
		printf("%d", A + C);
	}
	else if (B >= A && A >= C)
	{
		printf("%d", A + B);
	}
	else if (B >= C && C >= A)
	{
		printf("%d", B + C);
	}
	else if (C >= A && A >= B)
	{
		printf("%d", A + C);
	}
	else
	{
		printf("%d", B + C);
	}

	printf("\n");
	return (0);
}
