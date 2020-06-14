#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int x1, x2, x3, x4, x5;
	scanf("%d", &x1);
	scanf("%d", &x2);
	scanf("%d", &x3);
	scanf("%d", &x4);
	scanf("%d", &x5);
	if (x1 == 0) {
		printf("1\n");
	}
	else if (x2 == 0) {
		printf("2\n");
	}
	else if (x3 == 0) {
		printf("3\n");
	}
	else if (x4 == 0) {
		printf("4\n");
	}
	else if (x5 == 0) {
		printf("5\n");
	}
	return 0;
}
