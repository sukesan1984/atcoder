#include <stdio.h>
int main()
{
	int A;
	int B;
	double x;
	scanf("%d", &A);
	scanf("%d", &B);

	x = 1.0 - (double)B /(double)A;
	printf("%f\n", x * 100);
	return (0);
}
