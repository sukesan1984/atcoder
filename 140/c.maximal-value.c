#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int *B = malloc(N * sizeof(int));
    for (int i = 1; i < N; i++) {
        scanf("%d", &B[i]);
    }
    int ans = B[1];
    for (int i = 2; i < N; i++) {
        if (B[i-1] > B[i])
            ans += B[i];
        else
            ans += B[i-1];
    }
    ans += B[N-1];
    printf("%d\n", ans);

    return 0;
}
