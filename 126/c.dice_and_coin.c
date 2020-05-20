#include <stdio.h>
#include <stdlib.h>

// k < K
// k -> 0 になる確率
double prob(int N, int k, double *DP) {
    if (DP[k] != -1)
        return DP[k];
    if (k == 0)
        return DP[k] = 0;

    if (k > N) {
        if (k % 2 == 1) {
            DP[k] = 0;
        } else {
            DP[k] = prob(N, k / 2, DP) / 2.0;
        }
    } else {
        // そのものズバリが出た後に、裏が出る確率
        DP[k] = 1.0 / 2.0 / (double) N;
        if (k % 2 == 0) {
            // と、合わせて、k/2の値から来る場合を足し合わせる
            DP[k] += prob(N, k / 2, DP) / 2.0;
        }
    }
    //printf("DP[%d]: %lf\n", k, DP[k]);
    return DP[k];
}

int main () {
    // N面サイコロ
    // コイン
    int N;
    int K;

    scanf("%d", &N);
    scanf("%d", &K);

    double *DP = calloc(1 + K, sizeof(double));
    for (int i = 0; i < K; i++) {
        DP[i] = -1;
    }

    double ans = 0;
    for (int i = 1; i < K; i++){
        ans += prob(N, i, DP);
    }
    printf("%.10lf\n", (1.0 - ans));

    return 0;
}
