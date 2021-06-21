#include <stdio.h>
#include <stdlib.h>

long long create_double(int i)
{
	int keta = 1;
	long long after;
	long long result;

	after = i;
	while (i / 10)
	{
		keta++;
		i /= 10;
	}
	result = after;
	while (keta--)
		result *= 10;
	return (result + after);
}

int main()
{
	long long N;
	scanf("%lld", &N);
	int ans = 0;
	for (int i = 1; i < 1000000; i++)
	{
		if (create_double(i) <= N)
			ans++;
		else
			break;
	}

	printf("%d\n", ans);
	return (0);
}
