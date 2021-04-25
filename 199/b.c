#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;

	scanf("%d", &N);
	int *A;
	int *B;
	int max_a;
	int min_b;
	int ans;

	A = calloc(N, sizeof(int));
	B = calloc(N, sizeof(int));
	max_a = -1;
	min_b = 1001;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		max_a = (max_a <= A[i]) ? A[i] : max_a;
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &B[i]);
		min_b = (min_b >= B[i]) ? B[i] : min_b;
	}

	if (min_b < max_a)
		printf("0\n");
	else
		printf("%d\n", (min_b - max_a + 1));
	return (0);
}
