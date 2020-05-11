#include <stdio.h>

int main() {
    int A;
    int B;
    int C;
    int K;
    int ans = 0;

    scanf("%d", &A); // 1
    scanf("%d", &B); // 0
    scanf("%d", &C); // -1
    scanf("%d", &K); // K

    if (A >= K) {
        ans = K;
    } else {
        if (B >= (K - A)) {
            ans = A;
        } else {
            ans = A - (K - A - B);
        }
    }
    printf("%d\n", ans);
    return 0;
}
