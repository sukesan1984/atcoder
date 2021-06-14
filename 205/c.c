#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long abs_ll(long long a)
{
	return (a > 0) ? a : (-a);
}

int main()
{
	long long A;
	long long B;
	long long C;

	scanf("%lld", &A);
	scanf("%lld", &B);
	scanf("%lld", &C);

	// C: 偶数
	if (C % 2 == 0)
	{
		if (abs_ll(A) == abs_ll(B))
		{
			printf("=\n");
			return (0);
		}
		else if (abs_ll(A) > abs_ll(B))
		{
			printf(">\n");
			return (0);
		}
		else
		{
			printf("<\n");
			return (0);
		}
	}
	else
	{
		if (A >= 0 && B >= 0)
		{
			if (A == B)
			{
				printf("=\n");
				return (0);
			}
			else if (A > B)
			{
				printf(">\n");
				return (0);
			}
			else
			{
				printf("<\n");
				return (0);
			}
		}
		else if (A < 0 && B >= 0)
		{
			printf("<\n");
			return (0);
		}
		else if (A >= 0 && B < 0)
		{
			printf(">\n");
			return (0);
		}
		else
		{
			if (abs_ll(A) == abs_ll(B))
			{
				printf("=\n");
				return (0);
			}
			else if (abs_ll(A) < abs_ll(B))
			{
				printf(">\n");
				return (0);
			}
			else
			{
				printf("<\n");
				return (0);
			}
		}
	}
	return (0);
}
