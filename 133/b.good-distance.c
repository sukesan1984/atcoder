#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_integer(int *X_i, int *X_j, int D) {
    int sum = 0;
    for (int k = 1; k <= D; k++) {
        sum += (X_i[k] - X_j[k]) * (X_i[k] - X_j[k]);
    }
    int res = (int) sqrt(sum);
    return (res * res) == sum;
}

int main() {
    int N, D;
    scanf("%d", &N);
    scanf("%d", &D);
    int **X = malloc((1 + N) * sizeof(int*));
    for (int i = 1; i <= N; i++) {
        X[i] = malloc((1 + D) * sizeof(int));
        for (int j = 1; j <= D; j++) {
            scanf("%d", &X[i][j]);
        }
    }

    int ans = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (is_integer(X[i], X[j], D)) {
                ans += 1;
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
