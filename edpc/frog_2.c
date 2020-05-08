#include <stdio.h>

#define abs(a) (( (a) > 0) ? (a) : -(a))

int main() {
    int n;
    int k;

    scanf("%d", &n);
    scanf("%d", &k);
    int h[n];
    int S[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    S[0] = 0;
    S[1] = abs(h[1] - h[0]);
  	for (int i = 2; i < n; i++) {
        int min = -1;
        int current;
        for (int j = 1; j <= k && (i - j) >= 0; j++) {
            current = abs(h[i] - h[i - j]) + S[i - j];
            if (current < min || min == -1)
                min = current;
        }
        S[i] = min;
    }

    printf("%d\n", S[n-1]);
    return 0;
}
