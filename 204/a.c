#include <stdio.h>

#include <stdlib.h>

int main()
{
	int x;
	int y;

	scanf("%d", &x);
	scanf("%d", &y);
	if (x == y)
		printf("%d\n", x);
	else
	{
		if ((x == 0 && y == 1) || (x == 1 && y == 0))
		{
			printf("2\n");
		}
		else if ((x == 0 && y == 2) || (x == 2 && y == 0))
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return (0);
}
