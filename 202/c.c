#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;

	scanf("%d", &N);
	int *A;
	int *B;
	int *C;
	A = calloc(N, sizeof(int));
	B = calloc(N, sizeof(int));
	C = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &B[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &C[i]);
	}

	unsigned long long  *forA;
	unsigned long long *forC;

	forA = calloc(N + 1, sizeof(unsigned long long));
	forC = calloc(N + 1, sizeof(unsigned long long));

	// 各数字を調べる
	for (int i = 0; i < N; i++)
	{
		forA[A[i]]++;
	}
	for (int i = 0; i < N; i++)
	{
		forC[B[C[i] - 1]]++;
	}

	unsigned long long ans = 0;
	for (int i = 0; i <= N; i++)
	{
		ans += forA[i] * forC[i];
	}
	printf("%lld\n", ans);


	return (0);
}
