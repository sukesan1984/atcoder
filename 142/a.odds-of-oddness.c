#include <stdio.h>

int main () {
    int N;
    scanf("%d", &N);
    double ans = ((double)((N / 2) + N % 2)) / N;
    printf("%.10lf\n", ans);
    return 0;
}
