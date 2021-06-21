#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *str;
	char *N;
	int len;
	N = calloc(11, sizeof(char));
	scanf("%s", N);
	len = strlen(N);
	int ans = 1;
	int skip = 1;
	int head = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (N[i] != '0')
			skip = 0;
		if (skip && N[i] == '0')
			continue;
		if (i <= head)
			break;
//		printf("N[%d]:%d, N[%d]: %d\n", i, N[i], head, N[head]);
		if (N[i] == N[head])
		{
			head++;
			continue;
		}
		else
			ans = 0;
	}
	if (ans == 1)
		printf("Yes\n");
	else
		printf("No\n");

	return (0);
}
