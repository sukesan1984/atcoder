#include <stdio.h>

int count(int n)
{
	int cnt;
	cnt = 0;
	while ((n % 2) == 0)
	{
		cnt++;
		n /= 2;
	}
	return cnt;
}

int main()
{
	int N;
	int cnt;
	int max_cnt;
	int max_num;
	scanf("%d", &N);
	if (N == 1)
	{
		printf("1\n");
		return (0);
	}


	max_cnt = 0;
	max_num = 0;
	for (int i = 1; i <= N; i++)
	{
		cnt = count(i);
		if (cnt > max_cnt)
		{
			max_num = i;
			max_cnt = cnt;
		}
	}
	printf("%d\n", max_num);
	return (0);
}
