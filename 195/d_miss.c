#include <stdio.h>
#include <stdlib.h>

int compar_box(const void *a, const void *b)
{
	return (*(int**)a)[0] - (*(int**)b)[0];
}

int solve(int L, int R, int N, int M, int **nimotsu, int *X)
{
	int **newbox;
	int len;
	int ans;
	int haitta;

	haitta = 0;
	len = M - (R - L + 1);
	//printf("len: %d\n", len);
	if (len == 0)
		return (0);
	newbox = calloc(len, sizeof(int*));
	ans = 0;
	for (int i = 0; i < L - 1; i++)
	{
		newbox[i] = calloc(2, sizeof(int));
		newbox[i][0] = X[i];
		newbox[i][1] = 0;
	}
	for (int i = R; i < M; i++)
	{
		newbox[L - 1 + R - i] = calloc(2, sizeof(int));
		newbox[L - 1 + R - i][0] = X[i];
		newbox[L - 1 + R - i][1] = 0;
	}
	qsort(newbox, len, sizeof(int) * 2, compar_box);
	//printf("有効box\n");
	//for (int i = 0; i < len; i++)
	//{
	//	printf("%d: 許容:%d\n", i, newbox[i][0]);
	//}
	// 荷物の価値の高いやつから収まる箱があるかどうか？
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (nimotsu[i][0] <= newbox[j][0] && newbox[j][1] == 0)
			{
				ans += nimotsu[i][1];
				newbox[j][1] = 1;
				haitta = 1;
			}
			if (haitta)
				break;
		}
		haitta = 0;
	}
	for (int i = 0; i < len; i++)
	{
		free(newbox[i]);
	}
	free(newbox);
	return ans;
}

int compar_nimotsu(const void *a, const void *b)
{
	return (*(int**)b)[1] - (*(int**)a)[1];
}

int main()
{
	int N, M, Q;
	int ans;
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &Q);
	int **nimotsu;
	nimotsu = calloc(N + 1, sizeof(int*));

	for (int i = 0; i < N; i++)
	{
		nimotsu[i] = calloc(2, sizeof(int));
		scanf("%d", &nimotsu[i][0]);
		scanf("%d", &nimotsu[i][1]);
	}
	qsort(nimotsu, N, 2 * sizeof(int), compar_nimotsu);
	//for (int i = 0; i < N; i++)
	//{
	//	printf("%d: w: %d, v: %d\n", i, nimotsu[i][1], nimotsu[i][0]);
	//}
	int *X;
	X = calloc(M, sizeof(int));
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &X[i]);
	}

	int *L;
	int *R;
	L = calloc(Q + 1, sizeof(int));
	R = calloc(Q + 1, sizeof(int));
	for (int i = 1; i <= Q; i++)
	{
		scanf("%d", &L[i]);
		scanf("%d", &R[i]);
	}
	for (int i = 1; i <= Q; i++)
	{
		ans = solve(L[i], R[i], N, M, nimotsu, X);
		printf("%d\n", ans);
	}
	return (0);
}
