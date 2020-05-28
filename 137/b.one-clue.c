#include <stdio.h>

int main () {
    int K, X;
    scanf("%d", &K);
    scanf("%d", &X);

    //int min_val = X - K + 1;
    //int max_val = X + K - 1;

    for (int i = X - K + 1; i <= X + K - 1; i++) {
        printf("%d", i);
        if (i != X + K - 1)
            printf(" ");
    }
    return 0;
}
