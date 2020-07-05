#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	int N;
	scanf("%d", &N);
	char **S = malloc((N + 1) * sizeof(char*));
	int c_ac = 0;
	int c_wa = 0;
	int c_tle = 0;
	int c_re = 0;
	for (int i = 1; i <= N; i++)
	{
		S[i] = malloc(4 * sizeof(char));
		scanf("%s", S[i]);
		if(strcmp(S[i], "AC") == 0) {
			c_ac++;
		} else if (strcmp(S[i], "WA") == 0) {
			c_wa++;
		} else if (strcmp(S[i], "TLE") == 0) {
			c_tle++;
		} else {
			c_re++;
		}
	}
	printf("AC x %d\n", c_ac);
	printf("WA x %d\n", c_wa);
	printf("TLE x %d\n", c_tle);
	printf("RE x %d\n", c_re);

	return (0);
}
