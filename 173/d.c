#include <stdio.h>
#include <stdlib.h>

int	compar(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main ()
{
	long N;
	long ans = 0;
	scanf("%ld", &N);
	long *A = malloc((1 + N) * sizeof(long));
	for (int i = 0; i < N; i++)
	{
		scanf("%ld", &A[i]);
	}
	qsort(A, N, sizeof(long), compar);

	ans = A[0];
	for (int i = 1; i < N - 1; i++)
	{
		if (i % 2 == 1)
			ans += A[i / 2 + 1];
		else
			ans += A[i / 2];
	}

	printf("%ld\n", ans);
	return (0);
}
