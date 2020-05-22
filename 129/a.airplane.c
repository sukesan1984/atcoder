#include <stdio.h>

#define min(a, b) ((a) < (b)) ? (a) : (b)

int main () {
    int P, Q, R;
    scanf("%d", &P);
    scanf("%d", &Q);
    scanf("%d", &R);
    int ans = min(min((P + Q), (Q + R)), R + P);
    printf("%d\n", ans);
    return 0;
}
