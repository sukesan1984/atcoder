#include <stdio.h>

int solve(int N, int i, int j)
{
	return (4 * i + 7 * j) == N;
}

int main()
{
	int N;
	int max_a;
	int max_b;
	int ans;

	scanf("%d", &N);

	max_a = N / 4;
	max_b = N / 7;

	ans = 0;
	for (int i = 0; i <= max_a; i++)
	{
		for (int j = 0; j <= max_b; j++)
		{
			if (solve(N, i, j))
			{
				ans = 1;
				break;
			}
		}
		if (ans)
			break;
	}
	if (ans)
		printf("Yes\n");
	else
		printf("No\n");

	return (0);
}
