#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	long N, D;
	long *X;
	long *Y;
	int ans;
	scanf("%ld", &N);
	scanf("%ld", &D);


	X = malloc((1 + N) * sizeof(long));
	Y = malloc((1 + N) * sizeof(long));
	ans = 0;
	for(int i = 1; i <= N; i++)
	{
		scanf("%ld", &X[i]);
		scanf("%ld", &Y[i]);
		if (X[i] * X[i] + Y[i] * Y[i] <= D * D)
			ans++;
	}
	printf("%d\n", ans);

	return (0);
}
