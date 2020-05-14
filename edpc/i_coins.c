#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    double *p = malloc((N + 1) * sizeof(double));
    double **DP = malloc((N + 1) * sizeof(double*));
    for (int i = 1; i <= N; i++) {
        scanf("%lf", &p[i]);
    }
    for (int i = 0; i <= N; i++) {
        DP[i] = malloc((N + 1) * sizeof(double));
        for (int j = 0; j <= N; j++) {
            DP[i][j] = 0.0;
        }
    }

    // initialize
    DP[1][0] = 1.0 - p[1];
    DP[1][1] = p[1];

    //DP[i][j]: i枚目まででj枚が面の確率 (jは最大i)
    for (int i = 2; i <= N; i++) {
        DP[i][0] = DP[i-1][0] * (1.0 - p[i]); // i-1枚目で表が一枚も出てない状態で裏が出る
        for (int j = 1; j <= i; j++) {
            DP[i][j] = (DP[i-1][j] * (1.0 -p[i]) + DP[i-1][j-1] * p[i]);  // i-1枚目までで、j枚表が出てる時に裏が出る or j-1枚表が出てる状態で、表が出る
        }
    }

    double ans = 0.0;
    // ansは(N-1)/2 + 1ちょうど一枚表が多い確率からN枚表になる確率を足した値
    for (int i = (N - 1)/2 + 1; i <= N; i++) {
        ans += DP[N][i];
    }
    printf("%1.10lf\n", ans);

    return 0;
}
