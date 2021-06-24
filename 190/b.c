#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, S, D;
	scanf("%d", &N);
	scanf("%d", &S);
	scanf("%d", &D);
	int *X;
	int *Y;
	X = calloc(N, sizeof(int));
	Y = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &X[i]);
		scanf("%d", &Y[i]);
	}
	for (int i = 0; i < N; i++)
	{
		if (X[i] < S && Y[i] > D)
		{
			printf("Yes\n");
			return (0);
		}
	}
	printf("No\n");

	return (0);
}
