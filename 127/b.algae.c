#include <stdio.h>

int main () {
    int r;
    int D;
    int x;
    int i = 2001;

    scanf("%d", &r);
    scanf("%d", &D);
    scanf("%d", &x);
    for (; i <= 2010; i++) {
        x = r * x - D; // iの時の値がxに入ってる
        printf("%d\n", x);
    }

    return 0;
}
