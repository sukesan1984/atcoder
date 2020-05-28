#include <stdio.h>

#define max(a, b) (a) > (b) ? (a) : (b)

int main() {
    int A;
    int B;
    scanf("%d", &A);
    scanf("%d", &B);

    int ans = max(max((A + B), (A - B)), A * B);
    printf("%d\n", ans);

    return 0;
}
