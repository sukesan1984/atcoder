#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void *b)
{
	return *((int*)a) < *((int *)b);
}

int main()
{
	int N;
	scanf("%d", &N);
	char **S;
	int *T;
	int *origin;
	S = calloc(N, sizeof(char*));
	T = calloc(N, sizeof(int));
	origin = calloc(N, sizeof(int));

	for (int i = 0; i < N; i++)
	{
		S[i] = calloc(16, sizeof(char));
		scanf("%s", S[i]);
		scanf("%d", &T[i]);
		origin[i] = T[i];
	}
	qsort(T, N, sizeof(int), compar);

	int i;
	for (int j = 0; j < N; j++)
	{
		if (origin[j] == T[1])
		{
			i = j;
			break;
		}
	}

	printf("%s\n", S[i]);
	return (0);
}
