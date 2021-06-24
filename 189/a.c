#include <stdio.h>
#include <stdlib.h>

int main()
{
	char C[4];
	scanf("%s", C);
	if (C[0] == C[1] && C[1] == C[2])
		printf("Won\n");
	else
		printf("Lost\n");
	return (0);
}
