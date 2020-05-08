#include <stdio.h>

#define abs(a) (( (a) > 0) ? (a) : -(a))

int main() {
	int n;
  	scanf("%d", &n);
	//printf("%d\n", n);
    int h[n];
  	int S[n]; // ステップiに行き着くまでの最小の和を入れていく
    for (int i = 0; i < n; i++) {
      scanf("%d", &h[i]);
      //printf("%d\n", h[i]);
    }

    S[0] = 0;
    S[1] = abs(h[1] - h[0]);
  	for (int i = 2; i < n; i++) {
      //printf("h[i]: %d, h[i-1]: %d, h[i-2]: %d\n", h[i], h[i-1], h[i-2]);
      int p1 = abs(h[i] - h[i - 1]) + S[i - 1];
      //printf("p1: %d\n", p1);
      int p2 = abs(h[i] - h[i - 2]) + S[i - 2];
      //printf("p2: %d\n", p2);

      S[i] = (p1 > p2) ? p2 : p1;
    }
  	printf("%d\n", S[n-1]);
    return 0;
}
