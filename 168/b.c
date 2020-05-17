#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str) {
    int i = 0;
    int len = 0;
    while (*str++)
        len++;
    return len;
}

int main() {
    int K;
    char S[101];
    scanf("%d", &K);
    scanf("%s", S);

    int len = ft_strlen(S);
    char *ans;
    if (len <= K) {
        ans = S;
    } else {
        ans = malloc((K + 4) * sizeof(char));
        int i = 0;
        while (i < K) {
            ans[i] = S[i];
            i++;
        }
        ans[i] = '.';
        ans[i+1] = '.';
        ans[i+2] = '.';
        ans[i+3] = '\0';
    }
    printf("%s\n", ans);
    return 0;
}
