#include <stdio.h>
#include <stdlib.h>

int main () {
	long N;
	// 各数字の個数を保持しておく
	long *count = calloc(100000, sizeof(long));
	long prev_sum = 0;
	scanf("%ld", &N);
	long *A = malloc((1 + N) * sizeof(long));
	for (long i = 1; i <= N; i++)
	{
		scanf("%ld", &A[i]);
		count[A[i]] += 1;
		prev_sum += A[i];
	}
	long Q;
	scanf("%ld", &Q);
	long *sum = malloc((Q + 1) * sizeof(long));
	sum[0] = prev_sum;
	long *B = malloc((1 + Q) * sizeof(long));
	long *C = malloc((1 + Q) * sizeof(long));
	for(long i = 1; i <= Q; i++)
	{
		scanf("%ld", &B[i]);
		scanf("%ld", &C[i]);
		// Bの数
		long prev_count = count[B[i]];
		long add = (C[i] - B[i]) * prev_count;
		sum[i] = sum[i - 1] + add;
		count[B[i]] -= prev_count;
		count[C[i]] += prev_count;
	}

	for (long i = 1; i <= Q; i++)
	{
		printf("%ld\n", sum[i]);
	}

	return 0;
}
