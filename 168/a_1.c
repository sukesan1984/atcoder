#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int amari;
    amari = N % 10;
    char *ans;
    switch(amari) {
        case 0:
        case 1:
        case 6:
        case 8:
            ans = "pon";
            break;
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
            ans = "hon";
            break;
        case 3:
            ans = "bon";
            break;
    }
    printf("%s\n", ans);
    return 0;
}

