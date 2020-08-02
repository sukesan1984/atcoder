#include <stdio.h>
#include <stdlib.h>

int mod(int a, int K)
{
	return a % K;
}

int main()
{
	int K;

	scanf("%d", &K);
	int num = 7;
	int ans = 1;
	int *check = calloc(K, sizeof(int));
	if (K % 2 == 0)
	{
		printf("-1\n");
		return (0);
	}
	int m;
	do {
		m = mod(num, K);
		if (m == 0)
			break;
		if (check[m] == 1)
		{
			ans = -1;
			break;
		}
		check[m] = 1; // mではわりきれなかった。
		ans++;
		num = m * 10 + mod(7, K);
	} while(1);
	printf("%d\n", ans);
	return (0);
}
