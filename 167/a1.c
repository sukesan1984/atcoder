#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[11];
    char t[11];

    scanf("%s", s);
    scanf("%s", t);

    int i = 0;
    int len = strlen(t);
    while(i < (len - 1)) {
        if (s[i] != t[i])
        {
            printf("%s\n", "No");
            return 0;
        }

        i++;
    }
    printf("%s\n", "Yes");
    return 0;
}

