#include <stdio.h>
#include <math.h>

#define abs(a) (( (a) > 0) ? (a) : -(a))

long double custom_pow(long double a) {
    return a * a;
}

int main (){
    int A;
    int B;
    int H;
    int M;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &H);
    scanf("%d", &M);
    long double dA = (long double) A;
    long double dB = (long double) B;
    long double dM = (long double) M;
    long double dH = (long double) H;
    long double nasu_kaku;
    if (6.0 * dM > dH * 30.0 + 30.0 * dM / 60.0)
        nasu_kaku = (6.0 * dM - (dH * 30.0 + 30.0 * dM / 60.0));
    else
        nasu_kaku = (dH * 30.0 + 30.0 * dM / 60.0) - (6.0 * dM);
    //printf("360: %Lf\n", nasu_kaku);
    nasu_kaku = (nasu_kaku > 180.0) ? 360.0 - nasu_kaku : nasu_kaku;
    //printf("180 inai: %Lf\n", nasu_kaku);
    nasu_kaku = 1.0 / 360.0 * 2 * 3.1415926535897932384626 * nasu_kaku;
    //printf("pi: %Lf\n", nasu_kaku);
    long double ans = sqrtl(abs(custom_pow(dA) + custom_pow(dB) - 2.0 * dA * dB * cosl(nasu_kaku)));
    printf("%4.20Lf\n", ans);

    return 0;
}
