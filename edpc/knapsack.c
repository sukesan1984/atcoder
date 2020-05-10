#include <stdio.h>

int main() {
    int N;
    int W;
    scanf("%d", &N);
    scanf("%d", &W);
    int w[N];
    int v[N];
    long DP[N][W+1]; // [i番目の荷物][重さj以下で最大の価値の最大値]
    for (int i = 0; i < N; i++) {
        scanf("%d", &w[i]);
        scanf("%d", &v[i]);
    }

    // 初期値
    for (int j = 0; j < W + 1; j++) {
        if (j < w[0])
            DP[0][j] = 0;
        else
            DP[0][j] = v[0];
    }

    int max = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < W + 1; j++) {
            // w[i]がjより大きければ、iは持って帰れない。
            if (j < w[i]) {
                DP[i][j] = DP[i-1][j];
            } else {
            // 持って帰る場合
                DP[i][j] = ((DP[i-1][j - w[i]] + v[i]) > DP[i-1][j]) ? (DP[i-1][j - w[i]] + v[i]) : DP[i-1][j];
            }
        }
    }

    long ans = DP[N-1][W];
    printf("%ld\n", ans);
    return 0;
}
