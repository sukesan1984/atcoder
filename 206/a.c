#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int ans;

	scanf("%d", &N);
	ans = (int)((double)N * 1.08);
	if (ans == 206)
	{
		printf("so-so\n");
	}
	else if (ans < 206)
	{
		printf("Yay!\n");
	}
	else
	{
		printf(":(\n");
	}
	return (0);
}
