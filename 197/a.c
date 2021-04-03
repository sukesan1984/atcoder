#include <stdio.h>

int main()
{
	char s[4];
	char n[4];

	scanf("%s", s);
	n[0] = s[1];
	n[1] = s[2];
	n[2] = s[0];
	n[3] = '\0';
	printf("%s\n", n);
	return (0);
}
