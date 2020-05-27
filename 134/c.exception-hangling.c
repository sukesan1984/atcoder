#include <stdio.h>
#include <stdlib.h>

int f(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main () {
    int N;
    scanf("%d", &N);
    int *A = malloc((1 + N) * sizeof(int));
    int *copied = malloc((1 + N) * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        copied[i] = A[i];
    }
    qsort(A, N, sizeof(int), f);
    int first = A[0];
    int second = A[1];

    for (int i = 0; i < N; i++) {
        if (copied[i] == first)
            printf("%d\n", second);
        else
            printf("%d\n", first);
    }

    return 0;
}
