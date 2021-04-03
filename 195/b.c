#include <stdio.h>

int main()
{
	int A;
	int B;
	int W;

	int min;
	int max;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &W);
	// ちょうど割り切れる時
	if ((W * 1000 % B) == 0)
		min = W * 1000 / B;
	else
		min = W * 1000 / B + 1;
	if (min * A > W * 1000)
	{
		printf("UNSATISFIABLE\n");
		return (0);
	}

	if ((W * 1000) % A == 0)
		max = W * 1000 / A;
	else
		max = W * 1000 / A;
	if (max * B < W * 1000)
	{
		printf("UNSATISFIABLE\n");
	}
	printf("%d %d\n", min, max);
	return (0);
}
