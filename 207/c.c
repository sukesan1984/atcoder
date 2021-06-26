#include <stdio.h>
#include <stdlib.h>

typedef struct	s_set
{
	double s;
	double e;
}				t_set;

t_set calc(int t, int l, int r)
{
	double start;
	double end;
	if (t == 1)
	{
		start = l;
		end = r;
	}
	else if (t == 2)
	{
		start = l;
		end = r - 0.1;
	}
	else if (t == 3)
	{
		start = l + 0.1;
		end = r;
	}
	else
	{
		start = l + 0.1;
		end = r - 0.1;
	}
	t_set s = {start, end};
	return s;
}

int main()
{
	int N;
	scanf("%d", &N);
	int *t = calloc(N, sizeof(int));
	int *l = calloc(N, sizeof(int));
	int *r = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t[i]);
		scanf("%d", &l[i]);
		scanf("%d", &r[i]);
	}
	int ans = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			t_set i_set;
			t_set j_set;
			// 区間iと区間jが共通部分を持つかどうか
			i_set = calc(t[i], l[i], r[i]);
			j_set = calc(t[j], l[j], r[j]);
			if (
					(j_set.s >= i_set.s && j_set.s <= i_set.e) ||
					(i_set.s >= j_set.s && i_set.s <= j_set.e)
				)
			{
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return (0);
}
