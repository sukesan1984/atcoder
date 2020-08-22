#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	long long ans;
	scanf("%d", &N);
	long long *A;
	long long prev;

	A = malloc((1 + N) * sizeof(long long));
	ans = 0;
	scanf("%lld", &A[1]);
	prev = A[1];
	for (int i = 2; i <= N; i++) {
		scanf("%lld", &A[i]);
		if (A[i] < prev)
			ans += prev - A[i];
		else
			prev = A[i];
	}
	printf("%lld\n", ans);
	return (0);
}
