#include <stdio.h>
#include <stdlib.h>

void show(int **DP, int N, int S)
{
	printf("----");
	for (int j = 0; j <= S; j++)
	{
		printf("%0.2d,", j);
	}
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("%0.2d: ", i);
		for (int j = 0; j <= S; j++)
		{
			printf("%0.2d,", DP[i][j]);
		}
		printf("\n");
	}

}

int main()
{
	int N;
	int *T;

	scanf("%d", &N);
	T = calloc(N, sizeof(int));
	int S = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &T[i]);
		S += T[i];
	}

	// DP[i][j]: T[0]...T[i]のなかからいくつか選んで、jが作れるか否か
	// i: 0 <= i < N
	// j: 0 <= j <= sum(T[0]...T[N-1])
	// DP[N-1][...]がわかれば、S = sum(T[0]...T[N-1])として、S/2(繰り上げ）から大きなる値に向けて順に調べていったものの最小値が答え
	int **DP;

	//初期化
	DP = calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		DP[i] = calloc(S + 1, sizeof(int));
	}

	DP[0][0] = 1; // 料理を選択しないケース
	DP[0][T[0]] = 1; // 料理を選択したケース
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= S; j++)
		{
			// T[j]を選ばない時
			if (DP[i - 1][j] == 1)
			{
				DP[i][j] = 1;
				continue;
			}
			if (j >= T[i])
				DP[i][j] = (DP[i - 1][j - T[i]] == 1) ? 1 : 0;
		}
	}

	//show(DP, N, S);
	int start;

	start = ((S % 2) == 0) ? S / 2 : S / 2 + 1;
	for (int k = start; k <= S; k++)
	{
		if (DP[N-1][k] == 1)
		{
			printf("%d\n", k);
			break;
		}
	}
	return (0);
}
