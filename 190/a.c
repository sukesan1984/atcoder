#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A, B, C;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	char *aoki = "Aoki";
	char *takahashi = "Takahashi";
	if (A == B)
	{
		if (C == 0)
			printf("%s\n", aoki);
		else
			printf("%s\n", takahashi);
	}
	else
	{
		if (A > B)
			printf("%s\n", takahashi);
		else
			printf("%s\n", aoki);
	}

	return (0);
}
