#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int or(int A, int B)
{
	return A | B;
}

int xor(int A, int B)
{
	return A ^ B;
}

int min(int A, int B)
{
	return A < B ? A : B;
}

int main()
{
	int tmp_xor;
	int current_or;
	int ans;
	int N;
	scanf("%d", &N);
	int *A;
	A = calloc(N, sizeof(int));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	if (N == 1)
	{
		printf("%d\n", A[0]);
		return (0);
	}
	ans = 2147483647;
	for (int i = 0; i < pow(2, (N - 1)); i++)
	{
		//printf("%d: ", i);
		//初期化
		tmp_xor = -1;
		current_or = -1;
		for (int j = 1; j <= (N - 1); j++)
		{
			if (i >> (N - 1 - j) & 1)
			{
				if (j == 1)
				{
					current_or = A[1];
					tmp_xor = A[0];
					continue;
				}
				if (tmp_xor == -1)
				{
					tmp_xor = current_or;
					current_or = A[j];
				}
				else
				{
					tmp_xor = xor(current_or, tmp_xor);
					current_or = A[j];
				}
				//printf("%d", 1);
			}
			else
			{
				if (j == 1)
				{
					current_or = or(A[0], A[1]);
					continue;
				}
				current_or = or(current_or, A[j]);
				//printf("%d", 0);
			}
		}
		if (tmp_xor == -1)
			tmp_xor = current_or;
		else
			tmp_xor = xor(current_or, tmp_xor);
		ans = min(ans, tmp_xor);
		//printf("\n");
	}
	printf("%d\n", ans);
	return (0);
}
