#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n + 1];
    int b[n + 1];
    int c[n + 1];
    int S[n + 1][3];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i + 1]);
        scanf("%d", &b[i + 1]);
        scanf("%d", &c[i + 1]);
    }

    // 初期化
    // 初日の幸福度
    S[1][0] = a[1];
    S[1][1] = b[1];
    S[1][2] = c[1];

    for (int i = 2; i <= n; i++) {
        S[i][0] = (S[i-1][1] > S[i-1][2]) ? S[i-1][1] + a[i] : S[i-1][2] + a[i];
        S[i][1] = (S[i-1][0] > S[i-1][2]) ? S[i-1][0] + b[i] : S[i-1][2] + b[i];
        S[i][2] = (S[i-1][0] > S[i-1][1]) ? S[i-1][0] + c[i] : S[i-1][1] + c[i];
    }
    int ans;
    if (S[n][0] > S[n][1]) {
        if (S[n][0] > S[n][2]) {
            ans = S[n][0];
        } else {
            ans = S[n][2];
        }
    } else {
        if (S[n][1] > S[n][2]) {
            ans = S[n][1];
        } else {
            ans = S[n][2];
        }
    }
    //for (int i = 1; i <= n; i++) {
    //    printf("S[%d][0]: %d\n", i,  S[i][0]);
    //    printf("S[%d][1]: %d\n", i,  S[i][1]);
    //    printf("S[%d][2]: %d\n", i,  S[i][2]);
    //}
    printf("%d\n", ans);
}
