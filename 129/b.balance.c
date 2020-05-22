#include <stdio.h>
#include <stdlib.h>

#define abs(a) ((a) > 0) ? (a) : (-(a))

int main () {
    int N;
    scanf("%d", &N);
    int *W = malloc((1 + N) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &W[i]);
    }

    // initialize
    int S1 = W[1];
    int S2 = 0;
    for (int i = 2; i <= N; i++) {
        S2 += W[i];
    }

    int ans = abs(S1 - S2);
    for (int i = 2; i < N; i++) {
        S1 += W[i];
        S2 -= W[i];
        int current = abs(S1 - S2);
        if (current < ans)
            ans = current;
    }

    printf("%d\n", ans);
    return 0;
}

