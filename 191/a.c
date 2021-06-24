#include <stdio.h>
#include <stdlib.h>

int main()
{
	int V, T, S, D;
	scanf("%d", &V);
	scanf("%d", &T);
	scanf("%d", &S);
	scanf("%d", &D);

	if ((V * T <= D) && (V * S >= D))
		printf("No\n");
	else
		printf("Yes\n");

	return (0);
}
