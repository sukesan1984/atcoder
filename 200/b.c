#include <stdio.h>

int main()
{
	unsigned long long N;
	int K;
	unsigned long long ans;

	scanf("%lld", &N);
	scanf("%d", &K);

	for (int i = 0; i < K; i++)
	{
		if (N % 200 == 0)
			N /= 200;
		else
			N = N * 1000 + 200;
	}
	printf("%lld\n", N);
	return (0);
}
