#include <stdio.h>
#include <stdlib.h>

int main () {
    int N;
    int X;
    scanf("%d", &N);
    scanf("%d", &X);

    int *L = malloc((N + 1) * sizeof(int));
    int ans = 0;
    int *D = malloc((N + 1) * sizeof(int));
    D[1] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);
        if (i >= 2) {
            D[i] += D[i-1] + L[i-1];
            if (D[i] > X){
                ans = i - 1;
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    if ((D[N] + L[N]) > X)
        ans = N;
    else
        ans = N + 1;
    printf("%d\n", ans);

    return 0;
}
