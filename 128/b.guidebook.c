#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Restaurant {
    int index;
    int score;
    char *city;
} Restaurant;

void swap(Restaurant *a, Restaurant *b) {
    Restaurant tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void show(Restaurant **list, int length) {
    for (int i = 0; i < length; i++) {
        printf("%s, %d\n", list[i]->city, list[i]->score);
    }
}

Restaurant **merge_sort(Restaurant **list, int length) {
    if (length == 0 || length == 1)
        return list;
    Restaurant **left = merge_sort(list, length / 2);
    Restaurant **right = merge_sort(list + (length / 2), length - length / 2);
    int i = 0;
    int j = 0;
    int k = 0;
    Restaurant **tmp = malloc(length * sizeof(Restaurant*));
    while (i < length / 2 || j < (length - length / 2)) {
        if (i == length / 2) {
            tmp[k++] = right[j++];
            continue;
        }
        if (j == (length - length / 2)) {
            tmp[k++] = left[i++];
            continue;
        }

        if(strcmp(left[i]->city, right[j]->city) > 0) { // b, aみたいな
            tmp[k++] =  right[j++];
        } else if(strcmp(left[i]->city, right[j]->city) == 0) {
            if (left[i]->score < right[j]->score) {
                tmp[k++] =  right[j++];
            } else {
                tmp[k++] = left[i++];
            }
        } else {
            tmp[k++] = left[i++];
        }
    }

    for (int i = 0; i < length; i++) {
        list[i] = tmp[i];
    }
    free(tmp);
    return list;
}

int main() {
    int N;
    scanf("%d", &N);
    Restaurant **S = malloc(N * sizeof(Restaurant*));
    //int *P = malloc((N + 1) * sizeof(int));

    for (int i = 0; i < N; i++) {
        char *city = malloc(10 * sizeof(char));
        int score;
        scanf("%s", city);
        scanf("%d", &score);
        S[i] = malloc(sizeof(Restaurant));
        S[i]->city = city;
        S[i]->score = score;
        S[i]->index = i + 1;
    }

    S = merge_sort(S, N);
    //swap(S[0], S[4]);
    for (int i = 0; i < N; i++) {
        printf("%d\n", S[i]->index);
    }

    return 0;
}
