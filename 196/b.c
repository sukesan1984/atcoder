#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *X;

	X = calloc(103, sizeof(char));
	scanf("%s", X);
	while (*X)
	{
		if (*X == '.')
			break;
		printf("%c", *X);
		X++;
	}
	printf("\n");

	return (0);
}
