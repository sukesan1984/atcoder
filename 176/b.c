#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *s;
	int buff = 5;
	int ans;
	int ret;

	ans = 0;
	s = malloc((buff + 1) * sizeof(char));
	while ((ret = read(0, s, buff))) {
		if (ret == -1)
			printf("fail\n");
		s[ret] = '\0';
		for (int i = 0; i < ret; i++) {
			if (isdigit(s[i]))
				ans = (ans + (s[i] - '0') % 9) % 9;
		}
		if (strchr(s, '\n'))
			break;
	}
	if (ans % 9 == 0)
		printf("Yes\n");
	else
		printf("No\n");
	return (0);
}
