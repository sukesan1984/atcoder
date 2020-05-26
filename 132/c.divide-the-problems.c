#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void *b) {
    return *(int*) a - *(int*) b;
}

int main () {
    int N;
    scanf("%d", &N);
    int *d = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &d[i]);
    }
    qsort(d, N, sizeof(int), comp);
    int ans = d[N/2] - d[N/ 2 - 1];
    printf("%d\n", ans);
    return 0;
}
