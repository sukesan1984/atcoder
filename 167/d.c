#include <stdio.h>



int main() {
    int N;
    long K;
    scanf("%d", &N);
    scanf("%ld", &K);


    int A[N+1];
    int check[N+1];
    for (int i = 1; i < N+1; i++) {
        scanf("%d", &A[i]);
        check[i] = 0;
    }

    //printf("%d %ld\n", N, K);
    //for (int i = 1; i < N+1; i++) {
    //    printf("A[%d]: %d\n", i, A[i]);
    //}

    int ans = 0;;
    // 周期を見つける
    int start = 1;
    int next = A[start];
    check[start] = 0;
    check[next] = 1;
    int M = 2;
    if (K == 1) {
        ans = next;
        printf("%d\n", ans);
        return 0;
    }
    for (int i = 2; i < K + 1; i++) {
        next = A[next];
        if (i == K) {
            printf("%d\n", next);
            return 0;
        }
        if (check[next] >= 1) {
            break;
        }
        check[next] = i;
        M++;
    }

    //printf("untile loop %d\n", check[next]); // ループの開始に到達するまでのステップ数
    //printf("loop %d\n", M - check[next]); // ループ数

    int count = (K - check[next]) % (M - check[next]);
    if (count == 0) {
        printf("%d\n", next);
    } else {
        for (int i = 1; i < count + 1; i++) {
            next = A[next];
        }
        printf("%d\n", next);
    }

    return 0;
}
