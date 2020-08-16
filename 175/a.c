#include <stdio.h>
#include <string.h>

int	main()
{
	char S[3];
	int	ans = 0;

	scanf("%s", S);
	if (!strcmp(S, "RRR"))
		ans = 3;
	else if(!strcmp(S, "RRS"))
		ans = 2;
	else if(!strcmp(S, "RSR"))
		ans = 1;
	else if(!strcmp(S, "RSS"))
		ans = 1;
	else if(!strcmp(S, "SRR"))
		ans = 2;
	else if(!strcmp(S, "SRS"))
		ans = 1;
	else if(!strcmp(S, "SSR"))
		ans = 1;
	else if(!strcmp(S, "SSS"))
		ans = 0;
	printf("%d\n", ans);
	return (0);
}
