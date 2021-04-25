#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// aの位置とbの位置を交換する
void swap(char **ref, int a, int b, int N)
{
	char tmp_a;

	if (a < N)
	{
		tmp_a = ref[0][a];
		if (b < N)
		{
			ref[0][a] = ref[0][b];
			ref[0][b] = tmp_a;
		}
		else
		{
			ref[0][a] = ref[1][b - N];
			ref[1][b - N] = tmp_a;
		}
	}
	else
	{
		tmp_a = ref[1][a - N];
		if (b < N)
		{
			ref[1][a - N] = ref[0][b];
			ref[0][b] = tmp_a;
		}
		else
		{
			ref[1][a - N] = ref[1][b - N];
			ref[1][b - N] = tmp_a;
		}
	}
}


// 前半Nと後半Nを交換する
void flip(char **ref, int N)
{
	char *tmp;

	tmp = ref[0];
	ref[0] = ref[1];
	ref[1] = tmp;
}

int main()
{
	int N;
	char *S;
	char **ref;
	scanf("%d", &N);

	S = calloc(2 * N + 1, sizeof(char));
	ref = calloc(2, sizeof(char*));
	scanf("%s", S);
	ref[0] = S;
	ref[1] = S + N;
	int Q;

	scanf("%d", &Q);
	int *T;
	int *A;
	int *B;
	T = calloc(Q, sizeof(int));
	A = calloc(Q, sizeof(int));
	B = calloc(Q, sizeof(int));
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", &T[i]);
		scanf("%d", &A[i]);
		scanf("%d", &B[i]);
		if (T[i] == 1)
			swap(ref, A[i] - 1, B[i] - 1, N);
		else
			flip(ref, N);
	}

	for (int i = 0; i < N; i++)
	{
		write(1, &ref[0][i], 1);
	}
	for (int i = 0; i < N; i++)
	{
		write(1, &ref[1][i], 1);
	}
	printf("\n");

	return (0);
}

