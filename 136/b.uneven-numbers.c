#include <stdio.h>

int is_odd(int N) {
    int keta = 0;
    while (((N / 10) > 0) || (N % 10 > 0)) {
        keta += 1;
        N /= 10;
    }
    return (keta % 2 == 1);
}

int main () {
    int N;
    scanf("%d", &N);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (is_odd(i))
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}
