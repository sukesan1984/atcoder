#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *S;
	char *ans;

	S = calloc(100000 + 1, sizeof(char));
	ans = calloc(100000 + 1, sizeof(char));
	scanf("%s", S);
	int len = strlen(S);
	int j = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		char c;
		c = S[i];
		if (S[i] == '6')
			c = '9';
		else if(S[i] == '9')
			c = '6';

		ans[j] = c;
		j++;
	}
	printf("%s\n", ans);
	return (0);
}
