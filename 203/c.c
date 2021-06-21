#include <stdio.h>
#include <stdlib.h>

typedef struct	s_ab
{
	long long A;
	long long B;
}				t_ab;

int compar(const void *a, const void *b)
{
	long long A = (*(t_ab*)a).A;
	long long B = (*(t_ab*)b).A;
	if (A > B)
		return 1;
	else if (A < B)
		return -1;
	else
		return 0;
}

int main()
{
	int N;
	unsigned long long K;
	scanf("%d", &N);
	scanf("%lld", &K);
	t_ab *AB;
	AB = calloc(N, sizeof(t_ab));
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &(AB[i].A));
		scanf("%lld", &(AB[i].B));
	}

	qsort(AB, N, sizeof(t_ab), compar);
	unsigned long long current = 0;
	unsigned long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		unsigned long long distant;
		distant = AB[i].A - current;
		if (K < distant)
		{
			// この街にはたどり着けない
			ans =  current + K;
			K = 0;
			break;
		}
		else
		{
			current = AB[i].A;
			K = K - distant + AB[i].B;
		}
	}
	if (K > 0)
	{
		ans = current + K;
	}
	printf("%lld\n", ans);

	return (0);
}
