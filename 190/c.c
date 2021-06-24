#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	int *A;
	int *B;
	A = calloc(M, sizeof(int));
	B = calloc(M, sizeof(int));
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &A[i]);
		scanf("%d", &B[i]);
	}
	int K;
	scanf("%d", &K);
	int *C;
	int *D;
	C = calloc(K, sizeof(int));
	D = calloc(K, sizeof(int));
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &C[i]);
		scanf("%d", &D[i]);
	}
	// 0 ~ 2^K - 1まで
	int ans = 0;
	for (int i = 0; i < pow(2, K); i++)
	{
		int sara[101] = {0};
		int tmp = 0;
		// j番目の人がどっちにボールを置くか
		for (int j = 0; j < K; j++)
		{
//			printf("%d", (i >> j & 1));
			if ((i >> j) & 1)
				sara[C[j]] += 1;
			else
				sara[D[j]] += 1;
		}
//		printf("\n");
		for (int j = 0; j < M; j++)
		{
			if (sara[A[j]] > 0 && sara[B[j]] > 0)
				tmp++;
		}
		ans = (tmp > ans) ? tmp : ans;
	}
	printf("%d\n", ans);

	return (0);
}
