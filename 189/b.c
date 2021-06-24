#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, X;
	scanf("%d", &N);
	scanf("%d", &X);
	int *V = calloc(N, sizeof(int));
	int *P = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &V[i]);
		scanf("%d", &P[i]);
	}
	int nonda = 0;
	for (int i = 0; i < N; i++)
	{
		nonda += V[i] * P[i];
		if (nonda > X * 100)
		{
			printf("%d\n", i + 1);
			return (0);
		}
	}
	printf("-1\n");

	return (0);
}
