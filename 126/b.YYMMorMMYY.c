#include <stdio.h>

int is_month(int m) {
    return (m >= 1) && (m <= 12);
}

int main () {
    int S;
    scanf("%d", &S);

    int bottom_2 = S % 100;
    int top_2 = S / 100;

    char *ans;
    if (is_month(top_2) && is_month(bottom_2)) {
        ans = "AMBIGUOUS";
    } else if (is_month(top_2) && !is_month(bottom_2)) {
        ans = "MMYY";
    } else if (!is_month(top_2) && is_month(bottom_2)) {
        ans = "YYMM";
    } else {
        ans = "NA";
    }

    printf("%s\n", ans);
    return 0;
}
