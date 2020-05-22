#include <stdio.h>
#include <stdlib.h>

int main () {
    int N;
    int M;
    scanf("%d", &N);
    scanf("%d", &M);
    int *DP = malloc((1 + N) * sizeof(int));
    int *a = malloc((1 + M) * sizeof(int));
    DP[0] = 1;
    DP[1] = 1;
    for (int i = 1; i <= M; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 1) {
            DP[1] = 0;
            continue;
        }
        DP[a[i]] = -1;
    }
    for (int i = 2; i <= N; i++) {
        if (DP[i] == -1) {
            DP[i] = 0;
            continue;
        }
        DP[i] = 0;
        if (DP[i - 2] != 0)
            DP[i] = (DP[i] + DP[i - 2]) % 1000000007
  ;
        if (DP[i - 1] != 0)
            DP[i] = (DP[i] + DP[i - 1]) % 1000000007;
    }
    printf("%d\n", DP[N]);

    return 0;
}

