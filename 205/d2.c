#include <stdio.h>
#include <stdlib.h>

int lower_bound(unsigned long long *low, int begin, int end, unsigned long long k)
{
//	printf("begin: %d, end: %d\n", begin, end);
	if (begin == end)
		return begin;
	if ((begin + 1) == end)
	{
		if (low[begin] < k)
			return end;
		else
			return begin;
	}
	int current = (begin + end) / 2;
	if (low[current] < k)
	{
		return lower_bound(low, current, end, k);
	}
	else
	{
		return lower_bound(low, begin, current, k);
	}
}

void solve(unsigned long long *low, unsigned long long ki, unsigned long long *A, int N)
{
	unsigned long long ans;
	// kiが最大の有効数より大きい場合
	if (low[N-1] < ki)
	{
		ans = ki - low[N-1] + A[N];
		printf("%lld\n", ans);
		return;
	}
	int idx = lower_bound(low, 0, N - 1, ki);
	ans = A[idx + 1] - (low[idx] - ki) - 1;
	printf("%lld\n", ans);
}

int main()
{
	int N;
	int Q;

	scanf("%d", &N);
	scanf("%d", &Q);
	unsigned long long *A;

	A = calloc(N + 1, sizeof(unsigned long long));
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &A[i]);
	}
	A[0] = 0;
	unsigned long long *K;
	K = calloc(Q, sizeof(unsigned long long));
	for (int i = 0; i < Q; i++)
	{
		scanf("%lld", &K[i]);
	}

	unsigned long long *low;

	low = calloc(N, sizeof(unsigned long long));
	low[0] = A[1] - A[0] - 1;
	for (int i = 1; i < N; i++)
	{
		low[i] = low[i-1] + A[i+1] - A[i] - 1;
	}

//	for (int i = 0; i < N; i++)
//	{
//		printf("low[%d]: %lld\n", i, low[i]);
//	}

	for (int i = 0; i < Q; i++)
	{
//		printf("idx: %d\n", lower_bound(low, 0, N - 1, K[i]));
		solve(low, K[i], A, N);
	}

	return (0);
}
