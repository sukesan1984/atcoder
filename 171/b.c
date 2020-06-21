#include <stdio.h>
#include <stdlib.h>
int compar(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main () {
	int N, K;
	scanf("%d", &N);
	scanf("%d", &K);
	int *p = malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &p[i]);
	}
	qsort(p, N, sizeof(int), compar);
	int sum = 0;
	for (int i = 0; i < K; i++)
	{
		sum += p[i];
	}
	printf("%d\n", sum);

	return 0;
}
