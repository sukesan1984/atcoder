#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);
	int *A;
	int *B;
	A = calloc(N, sizeof(int));
	B = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		scanf("%d", &B[i]);
	}
	int min = 1000000;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tmp;
			// 同じ従業員がこなす場合
			if (i == j)
				tmp = A[i] + B[j];
			else if (A[i] < B[j])
				tmp = B[j];
			else
				tmp = A[i];
			if (min > tmp)
				min = tmp;
		}
	}
	printf("%d\n", min);
	return (0);
}
