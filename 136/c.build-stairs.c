#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *H = malloc((N + 1) * sizeof(int));
    int *DP = malloc((N + 1) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &H[i]);
    }

    DP[1] = H[1] - 1; // 減らしておいた方が可能性がある

    for (int i = 2; i <= N; i++) {
        // 単調減少になるかどうか
        if (DP[i - 1] > H[i]) {
            printf("No\n");
            return 0;
        } else if (DP[i - 1] == H[i]) {
            DP[i] = H[i];
        } else {
            DP[i] = H[i] - 1;
        }
    }

    printf("Yes\n");
    return 0;
}
