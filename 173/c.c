#include <stdio.h>
#include <stdlib.h>

int main () {
	int H, W, K;
	scanf("%d", &H);
	scanf("%d", &W);
	scanf("%d", &K);
	char **c;

	c = malloc((1 + H) * sizeof(char*));
	for (int i = 1; i <= H; i++)
	{
		c[i] = malloc((1 + W + 1) * sizeof(char));
		scanf("%s", c[i] + 1);
	}

	// パターンを出す
	int ans = 0;
	for (int i = 0; i <= 1 << H; i++)
	{
		for (int j = 0; j <= 1 << W; j++)
		{
			int count = 0;
			for (int k = 1; k <= H; k++)
			{
				for (int l = 1; l <= W; l++)
				{
					//printf("i: %d, j: %d, k :%d, k_f: %d, l :%d, l_f: %d, (%c), count: %d\n", i, j, k, (i >> (k - 1)) & 1, l, (j >> (l - 1)) & 1, c[k][l], count);
					// 塗り潰されてない
					if (i & 1 << (k - 1) && j  & 1 << (l - 1) && c[k][l] == '#')
						count++;
				}
			}
			if (count == K)
				ans++;
		}
	}
	printf("%d\n", ans);

	return (0);
}
