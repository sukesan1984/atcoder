#include <stdio.h>

int main () {
    char S[4];
    char T[4];
    scanf("%s", S);
    scanf("%s", T);
    int i = 0;
    int ans = 0;
    while(i < 3) {
        if (S[i] == T[i])
            ans++;
        i++;
    }
    printf("%d\n", ans);
    return 0;
}
