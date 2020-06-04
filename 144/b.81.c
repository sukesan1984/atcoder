#include <stdio.h>
#include <stdlib.h>

int main () {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= 9; i++) {
        if ((N / i) <= 9 && N % i == 0){
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");

    return 0;
}
