#include <stdio.h>
#include <stdlib.h>

int calculate_dp(int *DP, int k, int *a, int N) {
    if (DP[k] != 0)
        return DP[k];
    for (int i = N; i >= 1; i--) {
        if (k >= a[i]) {
            if (calculate_dp(DP, k - a[i], a, N) == 1) {
                //printf("相手が負ける選び方(k:%d, a[%d]): %d:", k, i, a[i]);
                return DP[k] = 2;
            }
        }
    }
    return DP[k] = 1;
}

int main () {
    int N;
    int K;
    scanf("%d", &N);
    scanf("%d", &K);

    int *a = malloc((N + 1) * sizeof(int));
    int *DP = calloc(K + 1, sizeof(int));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }

    calculate_dp(DP, K, a, N);

    if (DP[K] == 2)
        printf("%s\n", "First");
    else
        printf("%s\n", "Second");

    return 0;
}
