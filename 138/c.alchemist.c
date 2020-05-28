#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}



int main() {
    int N;
    scanf("%d", &N);
    int *v = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    qsort(v, N, sizeof(int), f);
    double ans = 0;
    for (int i = 0; i < N - 2; i++){
        ans += pow(2.0, N - 2 - i) * v[i];
    }
    ans += v[N-2];
    ans += v[N-1];
    ans /= pow(2.0, N - 1);
    printf("%.10f\n", ans);

    return 0;
}
