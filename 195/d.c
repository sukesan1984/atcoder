#include <stdio.h>
#include <stdlib.h>

int compar_box(const void *a, const void *b)
{
	return (*(int**)a)[0] - (*(int**)b)[0];
}

int compar_nimotsu(const void *a, const void *b)
{
	return (*(int**)b)[1] - (*(int**)a)[1];
}

int solve(int L, int R, int **nimotsu, int *X, int N, int M)
{
	int validsize;
	int idx;
	int j;
	int ans;
	// 有効な箱を取り出す
	// index L - Rまでが無効
	// 有効: (0 .. L - 1) (R + 1..M - 1)
	// 有効な箱の数は、 M - (R - L + 1)
	//printf("L: %d, R: %d\n", L, R);
	ans = 0;
	validsize = M - (R - L + 1);
	if (validsize == 0)
		return (ans);
	int **newbox;
	newbox = calloc(validsize, sizeof(int*));
	idx = 0;
	for (int i = 0; i < L; i++)
	{
		//printf("newbox b: %d\n", i);
		newbox[i] = calloc(2, sizeof(int));
		newbox[i][0] = X[i];
		newbox[i][1] = 0;
		idx = i + 1;
	}
	j = 0;
	for (int i = R + 1; i < M; i++)
	{
		//printf("newbox a: %d\n", idx + j);
		newbox[idx + j] = calloc(2, sizeof(int));
		newbox[idx + j][0] = X[i];
		newbox[idx + j][1] = 0;
		j++;
	}
	//printf("sort start\n");
	qsort(newbox, validsize, sizeof(int) * 2, compar_box);
	//printf("sorted\n");
	//for (int i = 0; i < validsize; i++)
	//{
	//	printf("i:%d, size: %d\n", i, newbox[i][0]);
	//}
	// 価値の高い荷物から試していく
	int haitta = 0;
	for (int i = 0; i < N; i++)
	{
		haitta = 0;
		for (int j = 0; j < validsize; j++)
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
	}
	for (int i = 0; i < validsize; i++)
	{
		free(newbox[i]);
	}
	free(newbox);
	return (ans);
}

int main()
{
	int N, M, Q;
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &Q);

	int **nimotsu;
	nimotsu = calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		nimotsu[i] = calloc(2, sizeof(int));
		scanf("%d", &nimotsu[i][0]); // W;
		scanf("%d", &nimotsu[i][1]); // V;
	}
	qsort(nimotsu, N, 2 * sizeof(int), compar_nimotsu);
	//for (int i = 0; i < N; i++)
	//{
	//	printf("%d: W: %d, V:%d\n", i, nimotsu[i][0], nimotsu[i][1]);
	//}

	int *X;
	X = calloc(M, sizeof(int));
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &X[i]);
	}
	int **query;
	query = calloc(Q, sizeof(int*));
	for (int i = 0; i < Q; i++)
	{
		query[i] = calloc(2, sizeof(int));
		scanf("%d", &query[i][0]);
		scanf("%d", &query[i][1]);
	}

	for (int i = 0; i < Q; i++)
	{
		int ans;
		ans = solve(query[i][0] - 1, query[i][1] - 1, nimotsu, X, N, M);
		printf("%d\n", ans);
	}

	return (0);
}
