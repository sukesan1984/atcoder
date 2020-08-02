#include <stdio.h>
#include <stdlib.h>

void	swap(char *i, char *j)
{
	char tmp;
	tmp = *i;
	*i = *j;
	*j = tmp;
}

int main()
{
	int N;
	scanf("%d", &N);
	char *c;
	c = malloc(N * sizeof(char));
	scanf("%s", c);
	int ans = 0;
	int i = 0;
	int j = N - 1;
	// 最初に出てきたWを探す
	for (; i < j; i++)
	{
		if (c[i] == 'W')
		{
			for (; i < j; j--)
			{
				if (c[j] == 'R')
				{
					swap(&c[i], &c[j]);
					ans++;
					break;
				}
			}
		}
	}
	printf("%d\n", ans);

	return (0);
}
