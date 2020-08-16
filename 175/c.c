#include <stdio.h>

#define abs(a) (a) > 0 ? (a) : (-(a))

int	main()
{
	long long X, K, D;
	long long ans;

	scanf("%lld", &X);
	X = abs(X);
	scanf("%lld", &K);
	scanf("%lld", &D);

	long long div;
	long long mod;
	div = X / D;
	mod = X % D;

	// 近づける数より原点が遠い
	if (div > K)
		ans = X - D * K;
	else
	{
		if ((K - div) % 2 == 0)
			ans = mod;
		else
			ans = D - mod;
	}
	printf("%lld\n", ans);
	return (0);
}
