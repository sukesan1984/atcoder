#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main () {
	int N;
	scanf("%d", &N);
	int *A = malloc(N * sizeof(int));
	int *exists = calloc(1, 1000000 * sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		exists[A[i]] += 1;
	}

	// ソートする
	qsort(A, N, sizeof(int), compar);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int warikireta = 0;
		// 同じ数字が存在する場合は、割り切れる
		if (exists[A[i]] > 1)
			continue;
		for (int j = 0; j < i; j++) {
			if ((A[i] / 100) < A[j]) {
				int k = 2;
				while (k < 100) {
					if (A[i] % k == 0 && exists[A[i] / k]) {
						warikireta = 1;
						break;
					}
					k++;
				}
				break;
			}

			if (A[i] % A[j] == 0) {
				warikireta = 1;
				break;
			}
		}
		if (warikireta == 0)
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}
