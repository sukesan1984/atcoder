#include <stdio.h>

long get_count(long A, long B, long target) {
    if (B < target)
        return 0;
    long mod_a = A % target;
    long mod_b = B % target;
    long initial = (mod_a == 0) ? A : A + (target - mod_a); // 最初に割り切れる値
    long last = B - mod_b;
    long initial_count = initial / target;
    long last_count = last / target;
    return last_count - initial_count + 1;
}

long gcd(long m, long n) {
    long tmp;
    while (m % n != 0) {
        tmp = n;
        n = m % n;
        m = tmp;
    }

    return n;
}

long lcm(long m, long n) {
    return m * n / gcd(m, n);
}

int main () {
    long A;
    long B;
    long C;
    long D;

    scanf("%ld", &A);
    scanf("%ld", &B);
    scanf("%ld", &C);
    scanf("%ld", &D);

    long divided_c = get_count(A, B, C);
    //printf("c: %ld\n", divided_c);
    long divided_d = get_count(A, B, D);
    //printf("d: %ld\n", divided_d);
    long divided_c_d = get_count(A, B, lcm(C, D));
    //printf("lcm: %ld\n", lcm(C, D));
    //printf("c_d: %ld\n", divided_c_d);

    long ans = (B - A + 1) - (divided_c - divided_c_d + divided_d);

    printf("%ld\n", ans);

    return 0;
}
