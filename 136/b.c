#include <stdio.h>

int solve(int n)
{
	int d;

	d = 1;
	while (n / 10)
	{
		d++;
		n /= 10;
	}
	return (d % 2);
}

int main()
{
	int N;
	int ans;

	scanf("%d", &N);
	ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (solve(i))
			ans++;
	}

	printf("%d\n", ans);
	return (0);
}
