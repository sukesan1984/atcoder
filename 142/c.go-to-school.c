#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int *A = malloc((1+N) * sizeof(int));
    int *ans = malloc((1+N) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        ans[A[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        printf("%d", ans[i]);
        if (i != N)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
