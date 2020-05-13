#include <stdio.h>
#include <stdlib.h>

int power(int a, int b) {
    if (b == 1)
        return a;
    return a * power(a, b - 1);
}

int main() {
    int H;
    int W;

    scanf("%d", &H);
    scanf("%d", &W);

    char **a = malloc((H + 1) * sizeof(char*));
    int **DP = malloc((H + 1) * sizeof(int*));
    for (int i = 1; i <= H; i++) {
        a[i] = malloc((W + 1) * sizeof(char));
        DP[i] = malloc((W + 1) * sizeof(int));
        char *add = a[i] + 1;
        scanf("%s", add);
    }
    DP[1][1] = 1;
    // initialize
    for (int i = 2; i <= H; i++) {
        if (DP[i-1][1] == 0) {
            DP[i][1] = 0;
        } else {
            if (a[i][1] == '#') {
                DP[i][1] = 0;
            } else {
                DP[i][1] = 1;
            }
        }
    }

    for (int j = 2; j <= W; j++) {
        if (DP[1][j-1] == 0) {
            DP[1][j] = 0;
        } else {
            if (a[1][j] == '#') {
                DP[1][j] = 0;
            } else {
                DP[1][j] = 1;
            }
        }
    }

    for (int i = 2; i <= H; i++) {
        for (int j = 2; j <= W; j++) {
            if (a[i][j] == '#') {
                DP[i][j] = 0;
            } else {
                DP[i][j] = (DP[i-1][j] % (power(10, 9) + 7) + DP[i][j-1] % (power(10, 9) + 7)) % (power(10, 9)  + 7);
            }
        }
    }


    printf("%d\n", DP[H][W]);

    return 0;
}
