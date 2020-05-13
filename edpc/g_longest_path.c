#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int i;
    struct list* next;
} LinkedList;

void push(LinkedList *list, int i) {
    LinkedList *l = malloc(sizeof(LinkedList*));
    l->i = i;

    while(list->next != NULL) {
        list = list->next;
    }
    list->next = l;
}

void show(LinkedList *list) {
    while(list != NULL) {
        printf("%d, ", list->i);
        list = list->next;
    }
    printf("\n");
}

int get_longest_path(LinkedList **path, int node, int *DP) {
    LinkedList *list = path[node];
    if (DP[node] != -1)
        return DP[node];
    int max = 0;
    if (list == NULL) {
        return DP[node] = 0;
    }
    while(list != NULL) {
        int length = get_longest_path(path, list->i, DP);
        if (length > max) {
            max = length;
        }
        list = list->next;
    }
    DP[node] = max + 1;
    return DP[node];
}

int     main() {
    int N;
    int M;

    scanf("%d", &N);
    scanf("%d", &M);

    int *x = malloc((M + 1) * sizeof(int));
    int *y = malloc((M + 1) * sizeof(int));
    LinkedList **path = malloc((N + 1) * sizeof(LinkedList*));
    int *DP = malloc((N + 1) * sizeof(int));
    //initialize
    for (int i = 1; i <= N; i++) {
        path[i] = NULL;
        DP[i] = -1;
    }

    for (int i = 1; i <= M; i++) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
        if (path[x[i]] == NULL) {
            LinkedList *list = malloc(sizeof(LinkedList*));
            list->i = y[i];
            list->next = NULL;
            path[x[i]] = list;
        } else {
            push(path[x[i]], y[i]);
        }
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        int length = get_longest_path(path, i, DP);
        if (max < length)
            max = length;
    }
    printf("%d\n", max);

    return 0;
}
