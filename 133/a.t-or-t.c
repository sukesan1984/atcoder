#include <stdio.h>

#define min(a, b) ((a) > (b)) ? (b) : (a)

int main () {
    int N;
    int A;
    int B;
    scanf("%d", &N);
    scanf("%d", &A);
    scanf("%d", &B);
    int ans = min(N * A, B);

    printf("%d\n", ans);
    return 0;
}
