#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int *A;
	int ans;

	scanf("%d", &N);
	ans = 0;
	A = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		if (A[i] > 10)
			ans += A[i] - 10;
	}
	printf("%d\n", ans);

	return (0);
}
