#include <stdio.h>
#include <stdlib.h>

#define abs(a) (a) < 0 ? (-(a)) : (a)

int main () {
	int X, N;
	scanf("%d", &X);
	scanf("%d", &N);
	int *p = malloc((1 + N) * sizeof(int));
	int dup = 0;
	int min = 100;
	int max = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
		if (p[i] < min)
			min = p[i];
		if (p[i] > max)
			max = p[i];
		if (X == p[i])
			dup = 1;
	}
	if (dup == 0) {
		printf("%d\n", X);
		return 0;
	}

	int i = 1;
	int ans;
	for (;;) {
		if (X - i < min) {
			ans = X - i;
			break;
		} else {
			int found = 0;
			for (int j = 1; j <= N; j++) {
				if ((X - i) == p[j])
					found = 1;
			}
			if (found == 0) {
				ans = X - i;
				break;
			}
		}

		if (X + i > max) {
			ans = X + i;
			break;
		} else {
			int found = 0;
			for (int j = 1; j <= N; j++) {
				if ((X + i) == p[j])
					found = 1;
			}
			if (found == 0) {
				ans = X + i;
				break;
			}
		}
		i++;
	}

	printf("%d\n", ans);
	return 0;
}
