#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int N, X, T;
	int ans;

	scanf("%d", &N);
	scanf("%d", &X);
	scanf("%d", &T);
	ans = T * (N / X);
	if (N % X != 0)
		ans += T;
	printf("%d\n", ans);
	return (0);
}
