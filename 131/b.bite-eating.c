#include <stdio.h>

#define abs(a) ((a > 0) ? (a) : (-(a)))

int main () {
    int N;
    int L;
    scanf("%d", &N);
    scanf("%d", &L);
    int sum = N * (L - 1) + ((N + 1) * N) / 2;
    //printf("sum: %d\n", sum);
    int min_abs = 1000000000;
    int min = 0;
    for (int i = 1; i <= N; i++) {
        if (abs(L + i - 1) < min_abs) {
            min_abs = abs(L + i - 1);
            min = L + i - 1;
            //printf("min_abs: %d\n", min_abs);
        }
    }

    printf("%d\n", sum - min);
    return 0;
}
