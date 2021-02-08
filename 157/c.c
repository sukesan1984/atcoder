#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solve(int n, int N, int *s, int *c, int M)
{
	int *a;
	int digit = 1;

	a = calloc(N, sizeof(int));
	while (n / 10)
	{
		a[N-digit] = n % 10;
		digit++;
		n /= 10;
	}
	a[N-digit] = n;
	if (digit != N)
		return (0);
	for (int i = 1; i <= M; i++)
	{
		if (a[s[i] - 1] != c[i])
			return (0);
	}
	return (1);
}

int main()
{
	int N, M;
	int *s;
	int *c;
	int max;
	int ans;

	scanf("%d %d", &N, &M);
	s = calloc(1 + M, sizeof(int));
	c = calloc(1 + M, sizeof(int));
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &s[i], &c[i]);
	}
	max = pow(10, N);
	ans = -1;
	for (int i = 0; i < max; i++)
	{
		if(solve(i, N, s, c, M))
		{
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);

	return (0);
}
