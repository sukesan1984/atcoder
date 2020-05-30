#include <stdio.h>
#include <stdlib.h>

int main () {
    int N;
    scanf("%d", &N);
    int *d = malloc((1+N) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
    }
    int ans = 0;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            ans += (d[i] * d[j]);
        }
    }

    printf("%d\n", ans);
    return 0;
}
