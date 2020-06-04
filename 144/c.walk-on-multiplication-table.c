#include <stdio.h>
#include <math.h>

int main () {
    long N;
    scanf("%ld", &N);
    long double sqrtNum = sqrt(N);
    long a = 1;
    long b = 1;
    long min = N - 1;
    for (long i = 2; i <= sqrtNum; i++) {
        if (N % i == 0) {
            a = i;
            b = N / i;
            if ((a + b - 2) < min)
                min = a + b - 2;
        }
    }

    printf("%ld\n", min);

    return 0;
}
