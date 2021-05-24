#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);
	unsigned long long *A;
	unsigned long long *B;
	unsigned long long *C;

	A = calloc(N, sizeof(unsigned long long));
	B = calloc(N, sizeof(unsigned long long));
	C = calloc(N, sizeof(unsigned long long));
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
		// indexに合わせておく
		A[i] -= 1;
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &B[i]);
		// indexに合わせておく
		B[i] -= 1;
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &C[i]);
		// indexに合わせておく
		C[i] -= 1;
	}
	unsigned long long *countA;
	unsigned long long *countB;
	countA = calloc(N, sizeof(unsigned long long));
	countB = calloc(N, sizeof(unsigned long long));
	for (int i = 0; i < N; i++)
	{
		// A[0] - A[N-1]で現れるindexの数をカウントしておく
		countA[A[i]]++;
	}
	for (int i = 0; i < N; i++)
	{
		// C[0] - C[N-1]のインデックスをBから取得して、カウントしておく
		countB[B[C[i]]]++;
	}
	unsigned long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += countA[i] * countB[i];
	}
	printf("%lld\n", ans);
	return (0);
}
