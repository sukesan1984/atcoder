#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long long N;
	scanf("%lld", &N);
	int *A;
	A = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	unsigned long long ans = 0;
	unsigned long long a_2 = 0;
	unsigned long long sum_a = 0;
	for (int i = 0; i < N; i++)
	{
		a_2 += A[i] * A[i];
		sum_a += A[i];
	}
	ans = N * a_2 - (sum_a) * (sum_a);
	printf("%lld\n", ans);
	return (0);
}
