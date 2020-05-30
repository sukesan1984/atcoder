#include <stdio.h>
#include <stdlib.h>

int main () {
    int N;
    scanf("%d", &N);
    char *S = malloc((1+N) * sizeof(char));
    scanf("%s", S);
    char prev = S[0];
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (prev != S[i])
            ans++;
        prev = S[i];
    }

    printf("%d\n", ans);
    return 0;
}
