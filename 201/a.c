#include <stdio.h>

int main()
{
	int A1;
	int A2;
	int A3;

	scanf("%d", &A1);
	scanf("%d", &A2);
	scanf("%d", &A3);
	if ((A3 - A2) == (A2 - A1))
		printf("Yes\n");
	else
	{
		if ((A3 - A1) == (A1 - A2))
			printf("Yes\n");
		else
		{
			if ((A1 - A3) == (A3 - A2))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return (0);
}
