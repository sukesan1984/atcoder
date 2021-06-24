#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int desc(const void *a, const void *b)
{
	return (*(char*)b - '0') - (*(char*)a - '0');
}

int asc(const void *a, const void *b)
{
	return (*(char*)a - '0') - (*(char*)b - '0');
}

void assign(long long n, char *s, int i)
{
	if (n / 10)
		assign (n / 10, s, i + 1);
	s[i] = '0' + (n % 10);
}

// iはⅩ桁
char *itoa(long long n)
{
	char *s;

	s = calloc(11, sizeof(char));
	for (int i = 0; i < 11; i++)
	{
		s[i] = '\0';
	}
	assign(n, s, 0);
	return (s);
}

long long g1(char *s)
{
	int len = strlen(s);
	qsort(s, len, sizeof(char), desc);
	long long l = strtoll(s, NULL, 10);
//	printf("g1: %s ll: %lld\n", s, l);
	return (l);
}
long long g2(char *s)
{
	int len = strlen(s);
	qsort(s, len, sizeof(char), asc);
	long long l = strtoll(s, NULL, 10);
//	printf("g2: %s ll: %lld\n", s, l);
	return (l);
}

long long f(char *s)
{
	long long l = g1(s) - g2(s);
//	printf("f: %lld\n", l);
	return (l);
}

int main()
{
	int N;
	int K;
	scanf("%d", &N);
	scanf("%d", &K);
	long long *a;

	a = calloc(K + 1, sizeof(long long));
	char *s = itoa(N);
	a[0] = N;
	free(s);
	for (int i = 1; i <= K; i++)
	{
		s = itoa(a[i - 1]);
		a[i] = f(s);
		free(s);
	}
	printf("%lld\n", a[K]);

	return (0);
}
