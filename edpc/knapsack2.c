#include <stdio.h>
long INF = 2147483647;

int main() {
    int N;
    int W;

    scanf("%d", &N);
    scanf("%d", &W);

    int w[N + 1];
    int v[N + 1];

    int max_v = 0;
    for (int i = 1; i < N + 1; i++) {
        scanf("%d", &w[i]);
        scanf("%d", &v[i]);
        max_v += v[i];
    }

    long DP[N + 1][max_v + 1];
    // initialize
    for (int j = 0; j <= max_v; j++) {
        if(j <= v[1]) {
            DP[1][j] = w[1];
        } else {
            DP[1][j] = INF;
        }
        //printf("DP[1][%d]: %ld\n", j, DP[1][j]);
    }

    for (int i = 2; i < N + 1; i++) {
        for (int j = 0; j <= max_v; j++) {
            if (j - v[i] <= 0) {
                DP[i][j] = (DP[i-1][j] < w[i]) ? DP[i-1][j] : w[i];
            } else {
                DP[i][j] = (DP[i-1][j - v[i]] + w[i] < DP[i-1][j]) ? (DP[i-1][j - v[i]] + w[i]) : (DP[i-1][j]);
            }
            //printf("DP[%d][%d]: %ld\n", i, j, DP[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < max_v + 1; i++) {
        if (DP[N][i] <= W && DP[N][i] != INF) {
            ans = i;
        }
    }

    printf("%d\n", ans);

    return 0;
}
