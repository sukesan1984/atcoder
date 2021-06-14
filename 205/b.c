#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int *A;
	int *c;

	scanf("%d", &N);
	A = calloc(N, sizeof(int));
	c = calloc(N, sizeof(int));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		A[i] -= 1;
		if (c[A[i]] == 0)
			c[A[i]] = 1;
		else
		{
			printf("No\n");
			return (0);
		}
	}
	// 同じ数字がなければ
	printf("Yes\n");
	return (0);
}
