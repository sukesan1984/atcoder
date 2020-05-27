#include <stdio.h>

#define max(a, b) (a) < (b) ? (b) : (a)

int main() {
    int A, B, C;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    int ans = max(C - (A - B), 0);
    printf("%d\n", ans);
    return 0;
}
