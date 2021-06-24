#include <stdio.h>
#include <stdlib.h>

int main()
{
	int X;
	scanf("%d", &X);
	printf("%d\n", 100 - (X % 100));

	return (0);
}
