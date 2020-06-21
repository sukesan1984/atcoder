#include <stdio.h>

int main () {
	char c;
	scanf("%c", &c);

	if (c >= 'A' && c <= 'Z')
		printf("A\n");
	else
		printf("a\n");
	return 0;
}
