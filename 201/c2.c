#include <stdio.h>
#include <stdlib.h>

char *itoa(int num)
{
	char *str;
	str = calloc(5, sizeof(char));
	str[0] = num / 1000 + '0';
	str[1] = (num % 1000) / 100 + '0';
	str[2] = ((num % 1000) % 100) / 10 + '0';
	str[3] = ((num % 1000) % 100) % 10 + '0';
	str[4] = '\0';
	return str;
}

int has_digit(char *str, int num)
{
	while (*str)
	{
		if ((*str - '0') ==  num)
			return (1);
		str++;
	}
	return (0);
}

int ok(int num, char *S)
{
	char *str;

	str = itoa(num);
	for (int i = 0; i < 10; i++)
	{
		if (S[i] == 'o')
		{
			// iという数字が入ってなければだめ
			if (!has_digit(str, i))
				return (0);
		}
		else if (S[i] == 'x')
		{
			// iという数字が入っていたらだめ
			if (has_digit(str, i))
				return (0);
		}
	}
	return (1);
}

int main()
{
	int ans;
	char *S;
	char *str;

	S = calloc(11, sizeof(char));
	scanf("%s", S);
	ans = 0;
	for (int i = 0; i <= 9999; i++)
	{
		if (ok(i, S))
			ans++;
	}
	printf("%d\n", ans);
	return (0);
}
