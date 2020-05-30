#include <stdio.h>
#include <stdlib.h>

int main () {
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);

    int *h = malloc((1+N) * sizeof(int));
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &h[i]);
        if (K <= h[i])
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
