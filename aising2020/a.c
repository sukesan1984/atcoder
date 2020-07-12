#include <stdio.h>

int main ()
{
	int L, R, d;
	int count = 0;
	scanf("%d", &L);
	scanf("%d", &R);
	scanf("%d", &d);
	for (int i = L; i <=R; i++)
	{
		if (i % d == 0)
			count++;
	}

	printf("%d\n", count);

	return (0);
}
