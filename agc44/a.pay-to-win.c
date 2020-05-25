#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) > (b)) ? (b) : (a)

typedef struct TestCase {
    long N;
    long A;
    long B;
    long C;
    long D;
} TestCase;

TestCase* create_test(long N, long A, long B, long C, long D) {
    TestCase *t = malloc(sizeof(TestCase));
    t->N = N;
    t->A = A;
    t->B = B;
    t->C = C;
    t->D = D;
    return t;
}

long get_coins(long k, long A, long B, long C, long D, long *DP) {
    if (DP[k] != 0)
        return DP[k];
    long min_coins = 2147483647;
    // 1 / 2
    if (k >= 2 && k % 2 == 0) {
        min_coins = get_coins(k / 2, A, B, C, D, DP) + A;
    }
    if (k >= 3 && k % 3 == 0)
        min_coins = min(get_coins(k / 3, A, B, C, D, DP) + B, min_coins);
    if (k >= 5 && k % 5 == 0)
        min_coins = min(get_coins(k / 5, A, B, C, D, DP) + C, min_coins);
    if (k >= 1)
        min_coins = min(get_coins(k - 1, A, B, C, D, DP) + D, min_coins);
    // 上から来るパターン
    // 2倍
    for (long i = 1; i <= (k - k / 2 - 1); i++) {
        long case2 = get_coins(k / 2 + i, A, B, C, D, DP) + A + ((k / 2 + i) * 2 - k) * D;
        min_coins = min(case2, min_coins);
        //printf("2 [%ld] from %ld [%ld], min_coins: %ld\n", k, (k / 2 + i) * 2, case2, min_coins);
    }
    // 3倍
    for (long i = 1; i <= (k - k / 3  - 1); i++) {
        long case3 = get_coins(k / 3 + i, A, B, C, D, DP) + B + ((k / 3 + i) * 3 - k) * D;
        min_coins = min(case3, min_coins);
        //printf("3 [%ld] from %ld [%ld], min_coins: %ld\n", k, (k / 3 + i) * 3, case3, min_coins);
    }
    // 5倍
    //printf("case 4 [%ld] %d\n", k, __LINE__);
    for (long i = 1; i <= (k - k / 5 - 1); i++) {
        long case4 = get_coins(k / 5 + i, A, B, C, D, DP) + C + ((k / 5 + i) * 5 - k) * D;
        min_coins = min(case4, min_coins);
        //printf("5 [%ld] from %ld [%ld], min_coins: %ld\n", k, (k / 5 + i) * 5, case4, min_coins);
    }
    return DP[k] = min_coins;
}

void test(long N, long A, long B, long C, long D) {
    long *DP = calloc(N + 1, sizeof(long));
    DP[0] = 0;
    DP[1] = D;
    DP[2] = min(min(D + A, D + D), D + C + 3 * D);
    long ans = get_coins(N, A, B, C, D, DP);
    //for (int i = 0; i <= N; i++) {
    //    printf("DP[%d]: %ld\n", i, DP[i]);
    //}
    printf("%ld\n", ans);
    free(DP);
}

int main () {
    int T;
    scanf("%d", &T);
    TestCase **cases = malloc(T * sizeof(TestCase*));
    for (int i = 0; i < T; i++) {
        long N;
        long A;
        long B;
        long C;
        long D;
        scanf("%ld", &N);
        scanf("%ld", &A);
        scanf("%ld", &B);
        scanf("%ld", &C);
        scanf("%ld", &D);
        cases[i] = create_test(N, A, B, C, D);
    }
    for (int i = 0; i < T; i++) {
        TestCase *t = cases[i];
        test(t->N, t->A, t->B, t->C, t->D);
    }
    return 0;
}
