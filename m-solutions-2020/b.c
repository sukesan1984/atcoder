#include <stdio.h>
#include <math.h>

int solve(int A, int B, int C, int i, int j, int k)
{
	A *= pow(2, i);
	B *= pow(2, j);
	C *= pow(2, k);
	return (B > A && C > B);
}

int main()
{
	int A, B, C;
	int K;
	scanf("%d %d %d", &A, &B, &C);
	scanf("%d", &K);
	int ans;

	ans = 0;
	for (int i = 0; i <= K; i++)
	{
		for (int j = 0; j <= K - i; j++)
		{
			for (int k = 0; k <= K - i - j; k++)
			{
				if (solve(A, B, C, i, j, k))
				{
					ans = 1;
					break;
				}
			}
			if (ans)
				break;
		}
		if (ans)
			break;
	}
	if (ans)
		printf("Yes\n");
	else
		printf("No\n");
	return (0);
}
