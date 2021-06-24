#include <stdio.h>
#include <stdlib.h>
int min(int a, int b)
{
	return (a < b) ? (a) : (b);
}

int max(int a, int b)
{
	return (a < b) ? (b) : (a);
}

int main()
{
	int N;
	scanf("%d", &N);
	int *A = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	int ans = 0;
	for (int l = 0; l < N; l++)
	{
		int x = -1;
		for (int r = l; r < N; r++)
		{
			if (x == -1)
				x = A[l]; // 最初はA[l]になる
			else
				x = min(x, A[r]);
			ans = max(ans, x * ((r - l) + 1));
		}
	}
	printf("%d\n", ans);
	return (0);
}
