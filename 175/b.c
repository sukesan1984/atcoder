#include <stdio.h>
#include <stdlib.h>
int	compar(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int	main()
{
	int	N;
	int	ans = 0;

	scanf("%d", &N);
	int *L;
	L = malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &L[i]);
	}
	qsort(L, N, sizeof(int), compar);

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (L[i] == L[j])
				continue;
			for (int k = j + 1; k < N; k++)
			{
				if (L[j] == L[k])
					continue;
				if (L[j] + L[k] > L[i])
					ans++;
			}
		}
	}
	printf("%d\n", ans);
	return (0);
}
