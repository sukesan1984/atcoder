#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int K;
	scanf("%d", &N);
	scanf("%d", &K);
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			ans += i * 100 + j;
		}
	}
	printf("%d\n", ans);
	return (0);
}
