#include <stdio.h>
#include <stdlib.h>

typedef struct Retval{
    long score;
    int start;
    int end;
} Retval;

Retval* create_retval(long score, int start, int end) {
    Retval *retval = malloc(sizeof(Retval));
    retval->score = score;
    retval->start = start;
    retval->end = end;
    return retval;
}

Retval* max_score(Retval*** DP, long *a, int start, int end) {
    Retval* result[4];
    if (start > end)
        return NULL;
    if (DP[start][end] != NULL)
        return DP[start][end];
    
    if (start == end){
        return DP[start][end] = create_retval(a[start], start + 1, end);
    }
    if ((end - start) == 1) {
        if (a[start] < a[end])
            return DP[start][end] = create_retval(a[end], start, end - 1);
        else
            return DP[start][end] = create_retval(a[start], start + 1, end);
    }

    Retval *oposite;
    Retval *next_my;
    // 自分がstartをとる場合
    //result[0] = create_retval(max_score(a, start + 2, end)->score + a[start], start + 1, end);
    //result[1] = create_retval(max_score(a, start + 1, end - 1)->score + a[start], start + 1, end);
    // 次の手番の人の動き
    oposite = max_score(DP, a, start + 1, end);
    next_my = max_score(DP, a, oposite->start, oposite->end);
    result[0] = create_retval(next_my->score + a[start], start + 1, end);

    // 自分がendをとる場合
    oposite = max_score(DP, a, start, end - 1);
    next_my = max_score(DP, a, oposite->start, oposite->end);
    result[1] = create_retval(next_my->score + a[end], start, end - 1);
    //result[2] = create_retval(max_score(a, start + 1, end - 1)->score + a[end], start, end - 1) ;
    //result[3] = create_retval(max_score(a, start, end - 2)->score + a[end], start, end - 1);
    Retval* max = NULL;
    for (int i = 0; i < 2; i++) {
        if (result[i] == NULL)
            continue;
        //printf("result[%d]: score:%ld start:%d, end: %d\n", i, result[i]->score, result[i]->start, result[i]->end);
        if (max == NULL || max->score < result[i]->score)
            max = result[i];
    }
    return DP[start][end] = max;
}

int main() {
    int N;
    scanf("%d", &N);
    long *a = malloc((N+1) * sizeof(long));
    Retval ***DP = malloc((N+1) * sizeof(Retval*));
    for (int i = 1; i <= N; i++) {
        scanf("%ld", &a[i]);
        DP[i] = calloc(N+1,  sizeof(Retval));
    }


    Retval *X = max_score(DP, a, 1, N);
    Retval *Y = max_score(DP, a, X->start, X->end);
    if (Y == NULL)
        printf("%ld\n", X->score);
    else 
        printf("%ld\n", X->score - Y->score);

    return 0;
}
