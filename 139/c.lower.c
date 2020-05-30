#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int *H = malloc((1+N) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &H[i]);
    }

    int max = 0;
    int prev_height = H[1];
    int move_num = 0;
    for (int i = 2; i <= N; i++) {
        if (prev_height >= H[i]) {
            move_num += 1;
        } else  {
            if (move_num > max)
                max = move_num;
            move_num = 0;
        }
        prev_height = H[i];
    }
    if (move_num > max)
        max = move_num;
    printf("%d\n", max);

    return 0;
}
