#include <stdio.h>
#include <stdlib.h>

int main () {
    int N;
    int M;

    scanf("%d", &N);
    scanf("%d", &M);
    int *L = malloc((M + 1) * sizeof(int));
    int *R = malloc((M + 1) * sizeof(int));

    int start = 0;
    int end = 0;
    for (int i = 1; i <= M; i++) {
        scanf("%d", &L[i]);
        scanf("%d", &R[i]);
        if (start == 0)
            start = L[i];
        if (end == 0)
            end = R[i];
        if (start <= L[i])
            start = L[i];
        if (end >= R[i])
            end = R[i];
    }
    int ans;
    if (start > end)
        ans = 0;
    else
        ans = (end - start) + 1;
    printf("%d\n", ans);

    return 0;
}
