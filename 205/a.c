#include <stdio.h>

int main()
{
	int A;
	int B;

	scanf("%d", &A);
	scanf("%d", &B);
	double ans;

	ans = ((double)A / (double)100) * (double)B;
	printf("%f\n", ans);

	return (0);
}
