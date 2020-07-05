#include <stdio.h>

int main() {
	int N;
	int ans;

	scanf("%d", &N);
	if (N %1000 == 0)
		ans = 0;
	else
		ans = (1000 - (N % 1000));

	printf("%d\n", ans);
	return (0);
}
