#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	char *S;
	S = malloc(21 * sizeof(char));

	scanf("%s", S);
	for (int i = 0; i < 3; i++) {
		printf("%c", S[i]);
	}
	printf("\n");
	return 0;
}
