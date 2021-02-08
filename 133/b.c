#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int solve(int *a, int *b, int D)
{
	int sum;
	int ans;

	sum = 0;
	for (int i = 1; i <= D; i++)
	{
		sum += pow((a[i] - b[i]), 2.0);
	}
	ans = (int)sqrt(sum);
	return ((ans * ans) == sum);
}

int main()
{
	int N;
	int D;
	int ans;
	int **X;

	scanf ("%d %d\n", &N, &D);
	X = calloc(N + 1, sizeof(int*));
	for (int i = 1; i < N + 1; i++)
	{
		X[i] = calloc(D + 1, sizeof(int));
		for (int j = 1; j < D + 1; j++)
		{
			scanf("%d", &X[i][j]);
		}
	}
	ans = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j < N + 1; j++)
		{
			if (solve(X[i], X[j], D))
				ans++;
		}
	}
	printf("%d\n", ans);
	return (0);
}
