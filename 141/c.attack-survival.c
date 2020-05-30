#include <stdio.h>
#include <stdlib.h>

int main () {
    int N, K, Q;
    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &Q);

    int *A = malloc((1 + Q) * sizeof(int));
    int *ans_count = calloc(1+N, sizeof(int));
    for (int i = 1; i <= Q; i++) {
        scanf("%d", &A[i]);
        ans_count[A[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        if ((K - Q + ans_count[i]) > 0)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
