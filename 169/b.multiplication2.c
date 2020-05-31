#include <stdio.h>
#include <stdlib.h>

int main () {
    int N;
    scanf("%d", &N);
    unsigned long long *A = malloc((1 + N) * sizeof(unsigned long long));
    unsigned long long ans = 1;
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
        if (A[i] == 0) {
            printf("0\n");
            return 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        unsigned long long remain  = 1000000000000000000ULL / ans;
        if (remain < A[i]) {
           printf("-1\n");
           return 0;
        }
        ans *= A[i];
    }
    printf("%lld\n", ans);

    return 0;
}
