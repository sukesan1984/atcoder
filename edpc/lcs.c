#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_s {
    char c;
    struct node_s *prev_node;
    int len;
}              Node;

Node *create_node(char c, Node* prev_node, int len) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->c = c;
    node->prev_node = prev_node;
    node->len = len;
    return node;
}

Node *create_null_node() {
    Node *node = (Node*) malloc(sizeof(Node));
    node->len = 0;
    node->c = 0;
    node->prev_node = NULL;
    return node;
}

int main() {
    char s[3001];
    char t[3001];
    scanf("%s", s);
    scanf("%s", t);
    int len_s = strlen(s);
    int len_t = strlen(t);

    //printf("%s len: %d\n", s, len_s);
    //printf("%s len: %d\n", t, len_t);

    //printf("0\n");
    Node ***DP;
    DP = malloc(len_s * sizeof(Node**));
    for (int i = 0; i < len_s; i++) {
        DP[i] = malloc(len_t * sizeof(Node*));
    }

    //Node* DP[len_s][len_t];
    //printf("0-1\n");

    // 初期化
    int has_same_char = 0;
    for (int i = 0; i < len_s; i++) {
        if (t[0] == s[i]) {
            DP[i][0] = create_node(t[0], NULL, 1);
            has_same_char = 1;
            continue;
        }

        if (has_same_char) {
            DP[i][0] = create_node(t[0], NULL, 1);
        } else {
            DP[i][0] = create_null_node();
        }
    //    printf("DP[%d][%d] char:%c, len:%d\n", i, 0, DP[i][0]->c, DP[i][0]->len);
    }
    //printf("1\n");

    has_same_char = 0;
    for (int j = 0; j < len_t; j++) {
        if (t[j] == s[0]) {
            DP[0][j] = create_node(s[0], NULL, 1);
            has_same_char = 1;
            continue;
        }
        if (has_same_char) {
            DP[0][j] = create_node(s[0], NULL, 1);
        } else {
            DP[0][j] = create_null_node();
        }
    }
    //printf("2\n");

    for (int i = 1; i < len_s; i++) {
        for (int j = 1; j < len_t; j++) {
            if (s[i] == t[j]) {
                DP[i][j] = create_node(s[i], DP[i-1][j-1], DP[i-1][j-1]->len + 1);
            }
            else {
                DP[i][j] = (DP[i-1][j]->len > DP[i][j-1]->len) ? DP[i-1][j] : DP[i][j-1];
            }
        }
    }

    //printf("3\n");

    char ans[3001];
    int i = 0;
    Node *current_node = DP[len_s - 1][len_t - 1];
    if (current_node->len == 0) {
        printf("\n");
        return 0;
    }

    do {
        if (current_node->c >= 'a' && current_node->c <= 'z')
            ans[i++] = current_node->c;
        current_node = current_node->prev_node;
    } while (current_node != NULL);
    i--;
    while(i >= 0)
        printf("%c", ans[i--]);
    printf("\n");
    return 0;
}
