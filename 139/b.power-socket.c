#include <stdio.h>

int main () {
    int A;
    int B;
    scanf("%d", &A);
    scanf("%d", &B);
    if (B == 1) {
        printf("%d\n", 0);
        return 0;
    }

    if (A >= B) {
        printf("%d\n", 1);
        return 0;
    }
    int ans = 2;
    for(;;) {
        if ((A + (ans - 1) * (A - 1)) >= B) {
            printf("%d\n", ans);
            return 0;
        }

        ans++;
    }

    return 0;
}
