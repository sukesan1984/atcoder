#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);
	int count = 0;
	int *a = malloc((1 + N) * sizeof(int));
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		if (i % 2 == 1 && a[i] % 2 == 1)
			count++;
	}
	printf("%d\n", count);

	return (0);
}

