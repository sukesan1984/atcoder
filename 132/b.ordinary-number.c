#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *p = malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    int ans = 0;
    for (int i = 2; i <= n - 1; i++) {
        int dif_1 = p[i] - p[i-1];
        int dif_2 = p[i] - p[i+1];
        if ((dif_1 < 0 && dif_2 > 0) || (dif_1 > 0 && dif_2 < 0))
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
