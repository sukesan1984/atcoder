#include <stdio.h>
#include <stdlib.h>

unsigned long long *ruisekiwa(int N, int k, unsigned long long **dp)
{
	unsigned long long *ruiseki;

	ruiseki = calloc(3 * N + 1, sizeof(unsigned long long));
	ruiseki[0] = 0;
	for (int i = 1; i <= 3 * N; i++)
	{
		ruiseki[i] = ruiseki[i - 1] + dp[k][i];
	}

	return ruiseki;
}

void calc_dp(int x, int N, unsigned long long **dp)
{
	for (int i = 0; i <= 3 * N; i++)
	{
		//初期化
		dp[0][i] = 0;
		dp[1][i] = 0;
		dp[2][i] = 0;
		dp[3][i] = 0;
		// 1 - Nまでは各数字を一回選ぶだけの一通り
		if (i <= N)
			dp[1][i] = 1;
	}
	unsigned long long *ruiseki1;
	ruiseki1 = ruisekiwa(N, 1, dp);
	for (int i = 1; i <= 2 * N; i++)
	{
		if (i <= N + 1)
			dp[2][i] = ruiseki1[i - 1];
		else
			dp[2][i] = ruiseki1[i - 1] - ruiseki1[i - N - 1];
//		printf("2この選び方: sum: %d, 個数: %d\n", i, dp[2][i]);
	}
	free(ruiseki1);
	unsigned long long *ruiseki2;
	ruiseki2 = ruisekiwa(N, 2, dp);
	for (int i = 1; i <= 3 * N; i++)
	{
		if (i <= N + 1)
			dp[3][i] = ruiseki2[i - 1];
		else
			dp[3][i] = ruiseki2[i - 1] - ruiseki2[i - N - 1];
//		printf("3この選び方: sum: %d, 個数: %d\n", i, dp[3][i]);
	}
	free(ruiseki2);
}

int main()
{
	int N;
	unsigned long long K;

	scanf("%d", &N);
	scanf("%lld", &K);
	unsigned long long **dp;
	dp = calloc(4, sizeof(unsigned long long*));
	for (int i = 0; i < 4; i++)
	{
		dp[i] = calloc(3 * N + 1, sizeof(unsigned long long));
	}

	calc_dp(3 * N, N, dp);
	int x; // K番目のときの総和値を求める
	for (int i = 3; i <= 3 * N; i++)
	{
		if (K <= dp[3][i])
		{
			x = i;
			break;
		}
		else
		{
			K -= dp[3][i];
		}
	}
//	printf("%d\n", x);
	// K番目のxの値がわかった
	// iを綺麗さの値と仮定する
	for (int i = 1; i <= N; i++)
	{
		// 美味しさの最小値の可能性としては
		int jmi = (x - i - N < 1) ? 1 : x - i - N;
		// 美味しさの最大値の可能性としては
		int jma = (x - i - 1 > N) ? N : x - i - 1;
//		printf("i: %d, jmi: %d, jma: %d\n", i, jmi, jma);
		//最小値のほうが最大値より大きければそのような綺麗さの値は取れないのでskip
		if (jmi > jma)
			continue;
		// Kが範囲に入ってなければ進めて次に進む
		if (K > jma - jmi + 1)
		{
			K -= (jma - jmi + 1);
			continue;
		}
		int y = jmi + K - 1;
		printf("%d %d %d\n", i, y, x - i - y);
		break;
	}

	return (0);
}
