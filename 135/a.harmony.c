#include <stdio.h>

int main() {
    int A;
    int B;
    scanf("%d", &A);
    scanf("%d", &B);
    if ((A + B) % 2 != 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    printf("%d\n", (A + B) / 2);

    return 0;
}
