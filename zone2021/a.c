#include <stdio.h>
#include <string.h>

int main()
{
	char S[13];
	char *itr;
	int count;

	scanf("%s", S);
	count = 0;
	itr = S;
	while (*itr)
	{
		if (!strncmp(itr, "ZONe", 4))
		{
			count++;
			itr += 4;
		}
		else
		{
			itr++;
		}
	}
	printf("%d\n", count);
	return (0);
}
