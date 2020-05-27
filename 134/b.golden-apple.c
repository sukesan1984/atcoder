#include <stdio.h>

int main () {
    int N;
    int D;
    scanf("%d", &N);
    scanf("%d", &D);
    int k = 1;
    int ans = 0;
    for(;;) {
        if ((2 * k * D + k) >= N) {
            ans = k;
            break;
        }
        k++;
    }

    printf("%d\n", ans);

    return 0;
}
