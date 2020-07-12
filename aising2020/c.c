#include <stdio.h>
#include <math.h>

void show_result(int N)
{
	int max;
	max = sqrt((double)N / (double)6);
	int count = 0;
	for (int x = 1; x <= max; x++)
	{
		int y_max = sqrt((double)(N - x * x) / (double)3) + (double)x * x / (double)9;
		for (int y = x; y <=y_max; y++)
		{
			int z = sqrt((double)(N - x * x - y * y - x * y) + (double)((x + y) * (x + y)) / (double)4) - (double)(x + y) / (double)2;
			if (z < y)
				continue;
			if (x * x + y * y + z * z + x * y + y * z + z * x == N)
			{
				if (x == y && y == z)
					count += 1;
				else if (x == y && y < z)
					count += 3;
				else if (x < y && y == z)
					count += 3;
				else
					count += 6;
			}
		}
	}
	printf("%d\n", count);
}

int main ()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		show_result(i);
	}

	return (0);
}
