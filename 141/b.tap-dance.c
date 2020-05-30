#include <stdio.h>
#include <string.h>

int main () {
    char S[101];
    scanf("%s", S);
    int len = strlen(S);
    for (int i = 0; i < len; i++) {
        if ((i + 1) % 2 == 0 && S[i] != 'R') {
            continue;
        } else if ((i + 1) % 2 == 1 && S[i] != 'L') {
            continue;
        } else {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");

    return 0;
}
