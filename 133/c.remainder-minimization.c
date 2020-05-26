#include <stdio.h>

int main () {
    int L;
    int R;
    scanf("%d", &L);
    scanf("%d", &R);

    int min = 2020;
    for (int i = L; i < R; i++) {
        for (int j = L + 1; j <= R; j++) {
            int v = i % 2019;
            int w = j % 2019;
            if (min > ((v * w) % 2019))
                min = (v * w) % 2019;
            if (min == 0) {
                printf("%d\n", min);
                return 0;
            }
        }
    }

    printf("%d\n", min);
    return 0;
}
