#include <stdio.h>
#include <stdlib.h>


int main () {
	int N;
	int D;
	int H;
	double x;
	double ans;
	scanf("%d", &N);
	scanf("%d", &D);
	scanf("%d", &H);
	int *d;
	int *h;
	d = calloc(N, sizeof(int));
	h = calloc(N, sizeof(int));

	ans = -2147483648;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &d[i]);
		scanf("%d", &h[i]);
		if (H < h[i])
			x = (double)(h[i] - H) * (double)D / (double)(D - d[i]) + (double)H;
		else
			x = (double)(d[i] * H - D * h[i]) / (double)(d[i] - D);
		//printf("%d, %d, %d, %f\n", i, d[i], h[i], x);
		ans = (x > ans) ? x : ans;
	}
	if (ans < 0)
		ans = 0.0;

	printf("%f\n", ans);
	return (0);
}
