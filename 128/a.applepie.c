#include <stdio.h>

int main () {
    int A;
    int P;

    scanf("%d", &A);
    scanf("%d", &P);

    P += A * 3;
    P /= 2;
    printf("%d", P);

    return 0;
}
