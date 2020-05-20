#include <stdio.h>

int main () {
    int A;
    int B;

    scanf("%d", &A);
    scanf("%d", &B);

    int ans = 0;
    if (13 <= A)
        ans = B;
    else if (6 <= A && 12 >= A)
        ans = B / 2;
    else
        ans = 0;
    printf("%d\n", ans);

    return 0;
}
