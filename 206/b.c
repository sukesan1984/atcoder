#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long long k;
	unsigned long long N;
	scanf("%lld", &N);
	k = 0;
	for (unsigned long long i = 1; i <= N; i++)
	{
		k += i;
		if (k >= N)
		{
			printf("%lld\n", i);
			break;
		}
	}
	return (0);
}
