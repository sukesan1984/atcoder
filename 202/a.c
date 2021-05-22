#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	int ans;
	ans = (7 - a) + (7 - b) + (7 - c);
	printf("%d\n", ans);
	return 0;
}
