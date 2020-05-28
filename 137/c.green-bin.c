#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

int sort_dict(const void *a, const void *b) {
    return strcmp((char*)a, (char*) b);
}

// if a and b is sorted.
// these are same strings.
int is_anagram(char *a, char *b) {
    return !strcmp(a, b);
}

int main() {
    int N;
    scanf("%d", &N);
    char (*s)[11] = malloc(N * sizeof(char[11]));
    for (int i = 0; i < N; i++) {
        scanf("%s", s[i]);
        qsort(s[i], 10, sizeof(char), f);
    }

    qsort(s, N, sizeof(char[11]), sort_dict);

    long ans = 0;
    long same_length = 1;
    char *current = s[0];

    for (int i = 1; i < N; i++) {
        if (!strcmp(s[i], s[i-1])) {
            same_length++;
        } else {
            if (same_length >= 2)
                ans += (same_length * (same_length - 1)) / 2;
            same_length = 1;
        }
        current = s[i];
    }
    if (same_length >= 2)
        ans += (same_length * (same_length - 1)) / 2;

    printf("%ld\n", ans);
    return 0;
}
