#include <stdio.h>

#define max(a, b) (a) < (b) ? (b) : (a)
int main() {
    int A;
    int B;

    scanf("%d", &A);
    scanf("%d", &B);

    printf("%d\n", max(A - 2 * B, 0));

    return 0;
}
