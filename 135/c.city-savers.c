#include <stdio.h>
#include <stdlib.h>

int main () {
    long N;
    scanf("%ld", &N);
    long *A = malloc((N + 2) * sizeof(long));
    long *B = malloc((N + 1) * sizeof(long));

    for (long i = 1; i <= N + 1; i++) {
        scanf("%ld", &A[i]);
    }

    for (long i = 1; i <= N; i++) {
        scanf("%ld", &B[i]);
    }

    long ans = 0;
    // initialize
    if (A[1] > B[1]) {
        ans += B[1];
    } else {
        ans += A[1];
        if ((A[2] - (B[1] - A[1])) > 0) {
            A[2] -= (B[1] - A[1]);
            ans += (B[1] - A[1]);
        } else {
            ans += A[2];
            A[2] = 0;
        }
    }

    for (long i = 2; i <= N; i++) {
        if (A[i] > B[i]) {
            ans += B[i];
        } else {
            ans += A[i];
            if ((A[i+1] - (B[i] - A[i])) > 0) {
                A[i+1] -= (B[i] - A[i]);
                ans += (B[i] - A[i]);
            } else {
                ans += A[i+1];
                A[i+1] = 0;
            }
        }
    }

    printf("%ld\n", ans);

    return 0;
}
