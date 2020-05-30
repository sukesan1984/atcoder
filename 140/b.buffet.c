#include <stdio.h>
#include <stdlib.h>

int main () {
    int N;
    scanf("%d", &N);
    int *A = malloc((1+N) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    int *B = malloc((1+N) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &B[i]);
    }
    int *C = malloc(N * sizeof(int));
    for (int i = 1; i < N; i++) {
        scanf("%d", &C[i]);
    }

    int ans = B[A[1]];
    for (int i = 2; i <= N; i++) {
        int prev = A[i-1];
        int current = A[i];
        ans += B[A[i]];
        if (current == (prev + 1))
            ans += C[current-1];
    }
    printf("%d\n", ans);


    return 0;
}
