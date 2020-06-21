#include <stdio.h>

void show(long i)
{
	if (i / 26 != 0) {
		show((i / 26) - 1);
	}
	long amari = i % 26;
	printf("%c", (char) amari + 'a');
}

int main () {
	long N;
	scanf("%ld", &N);
	show(N - 1);
	printf("\n");
	return 0;
}
