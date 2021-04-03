#include <stdio.h>

int main()
{
	int M;
	int H;

	scanf("%d", &M);
	scanf("%d", &H);
	if ((H % M) == 0)
		printf("Yes\n");
	else
		printf("No\n");
	return (0);
}
