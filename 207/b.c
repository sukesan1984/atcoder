#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long long A, B, C, D;
	scanf("%lld", &A);
	scanf("%lld", &B);
	scanf("%lld", &C);
	scanf("%lld", &D);
	if (C * D <= B)
	{
		printf("-1\n");
		return (0);
	}
	int n = 0;
	while (1)
	{
		if (A + n * B <= (n * C) * D)
		{
			printf("%d\n", n);
			return (0);
		}
		n++;
	}

	// n 回やった後
	return (0);
}
