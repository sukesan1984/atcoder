#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int M;

    scanf("%d", &N);
    scanf("%d", &M);
    int *k = malloc((N + 1) * sizeof(int));
    int **s = malloc((M + 1) * sizeof(int*));
    for (int i = 1; i <= M; i++) {
        scanf("%d", &k[i]);
        s[i] = malloc((k[i] + 1) * sizeof(int));
        for (int j = 1; j <= k[i]; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    int *p = malloc((M + 1) * sizeof(int));
    for (int i = 1; i <=M; i++) {
        scanf("%d", &p[i]);
    }

    // N = 2
    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        int *state = malloc((N + 1) * sizeof(int));
        for (int j = 1; j <= N; j++) {
            state[j] = ((i >> (j - 1)) % 2 == 1);
        }
        int all_on = 1;
        for (int l = 1; l <= M; l++) {
            int sum_on = 0;
            for (int o = 1; o <= k[l]; o++) {
                sum_on += state[s[l][o]];
           }
            if (p[l] != (sum_on % 2)) {
                all_on = 0;
                break;
            }
        }
        if (all_on == 1)
            ans++;
    }

    printf("%d", ans);

    return 0;
}
