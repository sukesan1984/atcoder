#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_lower(char c)
{
	return c >= 97 && c <= 122;
}

int is_upper(char c)
{
	return c >= 65 && c <= 90;
}


int main()
{
	char *S;
	int len;

	S = calloc(1001, sizeof(char));
	scanf("%s", S);
	len = strlen(S);

	for (int i = 0; i < len; i++)
	{
		if ((i % 2) == 1)
		{
			if (is_lower(S[i]))
			{
				printf("No\n");
				return (0);
			}
		}
		else
		{
			if (is_upper(S[i]))
			{
				printf("No\n");
				return (0);
			}
		}
	}
	printf("Yes\n");
	return (0);
}
