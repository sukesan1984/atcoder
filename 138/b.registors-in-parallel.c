#include <stdio.h>
#include <stdlib.h>

int main () {
    int N;
    scanf("%d", &N);
    int *A = malloc((1 + N) * sizeof(int));
    double total_mul = 1;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        total_mul *= A[i];
    }
    double total_plus = 0;
    for (int i = 1; i <= N; i++) {
        total_plus += total_mul / A[i];
    }
    printf("%.9f\n", total_mul / total_plus);

    return 0;
}
