#include <stdio.h>

int main () {
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);
    if (A <= 9 && B <= 9)
        printf("%d\n", A * B);
    else
        printf("-1\n");
    return 0;
}
