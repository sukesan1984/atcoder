#include <stdio.h>
#include <math.h>

int main () {
    long A;
    double B;
    scanf("%ld", &A);
    scanf("%lf", &B);

    long seisu = (long) B;
    double shosu = B - seisu;
    long shosu100 = roundl(shosu * 100);

    //printf("%lf\n", shosu * 100);
    //printf("%ld\n", shosu100);

    long ans = A * seisu + ((A * shosu100) / 100);
    printf("%ld\n", ans);

    return 0;
}
