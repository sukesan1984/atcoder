#include <stdio.h>
#include <stdlib.h>



int main()
{
	int N;
	int i;
	int *X;
	int *A;
	int *P;
	int max = 2147483647;

	int ans;

	scanf("%d", &N);
	X = calloc(N + 1, sizeof(int));
	A = calloc(N + 1, sizeof(int));
	P = calloc(N + 1, sizeof(int));

	ans = max;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]); // A分
		scanf("%d", &P[i]); // P円
		scanf("%d", &X[i]); // X台
		// n分後には n / 2台減る
		if ((X[i] - A[i]) > 0)
			ans = (P[i] < ans) ? P[i] : ans;
	}
	if (ans == max)
		ans = -1;
	printf("%d\n", ans);
	return (0);
}
