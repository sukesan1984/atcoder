#include <stdio.h>
#include <stdlib.h>

int solve(int n)
{
	int cnt;

	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if ((n % i) == 0)
			cnt++;
	}
	if ((cnt == 8) && (n % 2))
		return (1);
	return (0);
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
	//105 = 5 * 3 * 7 = 1, 3, 5, 7, 15, 21, 35, 105
	return (0);
}
