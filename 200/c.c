#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);
	int *A;
	unsigned long long ans;
	unsigned long long amari[200];
	for (int i = 0; i < 200; i++)
	{
		amari[i] = 0;
	}
	A = calloc(N, sizeof(int));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		amari[A[i] % 200] += 1;
	}
	ans = 0;
	for (int i = 0; i < 200; i++)
	{
		if (amari[i] != 0 && amari[i] != 1)
		{
			ans += (amari[i] * (amari[i] - 1)) / 2;
		}
	}

	printf("%lld\n", ans);

	return (0);
}
