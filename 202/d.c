#include <stdio.h>
#include <stdlib.h>

void solve(int a, int b, unsigned long K, unsigned long long **dp)
{
	if (K == 1)
	{
		for (int i = 0; i < a; i++)
			printf("a");
		for (int i = 0; i < b; i++)
			printf("b");
		return ;
	}
	if (dp[a - 1][b] > K)
	{
		printf("a");
		solve(a - 1, b, K, dp);
		return ;
	}
	else if (dp[a - 1][b] == K)
	{
		printf("a");
		for (int i = 0; i < b; i++)
			printf("b");
		for (int i = 0; i < a - 1; i++)
			printf("a");
	}
	else
	{
		printf("b");
		solve(a, b - 1, K - dp[a - 1][b], dp);
		return ;
	}
}

int main()
{
	int A;
	int B;
	unsigned long long K;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%lld", &K);
	// aの数とbの数から何通りの並べ替えの数があるかを事前に計算する
	unsigned long long **dp;

	dp = calloc(A + 1, sizeof(unsigned long long));
	for (int i = 0; i <= A; i++)
	{
		dp[i] = calloc(B + 1, sizeof(unsigned long long));
	}
	dp[0][0] = 0;
	// Aが一つもなければ、1通りしかない
	for (int i = 1; i <= B; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i <= A; i++)
	{
		dp[i][0] = 1;
	}
	for (int i = 1; i <= A; i++)
	{
		for (int j = 1; j <= B; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	solve(A, B, K, dp);
	printf("\n");
	return (0);
}
