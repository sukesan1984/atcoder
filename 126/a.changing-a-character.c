#include <stdio.h>

int main() {
    int N;
    int K;

    scanf("%d", &N);
    scanf("%d", &K);

    char S[50];
    scanf("%s", S);
    S[K-1] += ('a' - 'A');
    printf("%s\n", S);

    return 0;
}
