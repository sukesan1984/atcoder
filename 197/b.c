#include <stdio.h>
#include <stdlib.h>

int look(int i, int j, int H, int W, char **S, int direction)
{
	int ans;

	if (i < 0 || i >= H || j < 0 || j >= W)
		return (0);
	if (S[i][j] == '#')
		return (0);
	ans = 1;
	if (direction == 1)
		return ans + (look (i, j - 1, H, W, S, 1));
	else if (direction  == 2)
		return ans + (look (i, j + 1, H, W, S, 2));
	else if (direction == 3)
		return ans + (look (i - 1, j, H, W, S, 3));
	else
		return ans + (look (i + 1, j, H, W, S, 4));
	return (ans);
}

int get_count(int i, int j, int H, int W, char **S)
{
	int ans;

	ans = 0;
	if (i < 0 || i >= H || j < 0 || j >= W)
		return (0);
	if (S[i][j] == '#')
		return (0);
	ans++;

	ans += look(i, j - 1, H, W, S, 1);
	ans += look(i, j + 1, H, W, S, 2);
	ans += look(i - 1, j, H, W, S, 3);
	ans += look(i + 1, j, H, W, S, 4);
	return (ans);
}

int main()
{
	int H;
	int W;
	int X;
	int Y;
	char **S;
	int ans;

	scanf("%d", &H);
	scanf("%d", &W);
	scanf("%d", &X);
	scanf("%d", &Y);
	S = calloc(H, sizeof(char*));
	for (int i = 0; i < H; i++)
	{
		S[i] = calloc(W + 1, sizeof(char));
		scanf("%s", S[i]);
	}

	ans = get_count(X - 1, Y - 1, H, W, S);
	printf("%d\n", ans);

	return (0);
}
