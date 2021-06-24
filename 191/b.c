#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int X;

	scanf("%d", &N);
	scanf("%d", &X);
	int *A;
	A = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	int is_first = 1;
	for (int i = 0; i < N; i++)
	{
		if (A[i] != X)
		{
			if (is_first)
			{
				printf("%d", A[i]);
				is_first = 0;
			}
			else
				printf(" %d", A[i]);
		}
	}
	printf("\n");
	return (0);
}
