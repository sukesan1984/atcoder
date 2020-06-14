#include <stdio.h>

int main() {
	int X, Y;
	scanf("%d", &X);
	scanf("%d", &Y);

	if (4 * X >= Y && (4 * X - Y) % 2 == 0 && Y >= 2 * X && (Y - 2*X) % 2 == 0)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}

