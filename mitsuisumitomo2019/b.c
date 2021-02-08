#include <stdio.h>

int main()
{
	int N;
	int ans;

	scanf("%d", &N);
	ans = N / 1.08;
	if ((int)(ans * 1.08) == N)
		printf("%d\n", ans);
	else if ((int)((ans + 1) * 1.08) == N)
		printf("%d\n", ans + 1);
	else
		printf(":(\n");

	return (0);
}
