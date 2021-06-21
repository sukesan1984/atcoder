#include <stdio.h>
#include <stdlib.h>
int compar(const void *a, const void *b)
{
	return *((unsigned long long*)a) - *((unsigned long long*)b);
}

int main()
{
	unsigned long long N;

	scanf("%lld", &N);
	unsigned long long *A;
	A = calloc(N, sizeof(unsigned long long));
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
	}
	qsort(A, N, sizeof(unsigned long long), compar);
	// 全体の組み合わせ
	unsigned long long ans;
	ans = (N * (N - 1)) / 2;
	unsigned long long prev;
	prev = A[0];
	unsigned long long count = 1;
	for (int i = 1; i < N; i++)
	{
		if (prev == A[i])
			count++;
		else
		{
			ans -= (count * (count - 1)) / 2;
			prev = A[i];
			count = 1;
		}
	}
	ans -= (count * (count - 1)) / 2;
	printf("%lld\n", ans);

	return (0);
}
