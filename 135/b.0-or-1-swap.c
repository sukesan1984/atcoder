#include <stdio.h>
#include <stdlib.h>

int f (const void *a, const void *b) {
    return *(int *)a - *(int*)b;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void show(int *arr, int N) {
    for (int i = 0; i < N; i++) {
        printf("[%d]: %d\n", i, arr[i]);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int *p = malloc(N * sizeof(int));
    int *sorted = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
        sorted[i] = p[i];
    }
    qsort(sorted, N, sizeof(int), f);
    // 交換しないケース確認
    int same = 1;
    for (int k = 0; k < N; k++) {
        if (p[k] != sorted[k]) {
            same = 0;
            break;
        }
    }
    if (same == 1) {
        printf("YES");
        return 0;
    }


    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(p+i, p+j);
            int same = 1;
            for (int k = 0; k < N; k++) {
                if (p[k] != sorted[k]) {
                    same = 0;
                    break;
                }
            }
            if (same == 1) {
                printf("YES");
                return 0;
            }
            swap(p+i, p+j);
        }
    }

    printf("NO");
    return 0;
}
