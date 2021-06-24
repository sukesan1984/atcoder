#include <stdio.h>
#include <stdlib.h>

// 左上が頂点かどうかを判定する
// 頂点のケース
// (i-1,j-1) (i-1,j)
// (i,j-1)   (i,j)
// 1)
// ..
// .#
// 2)
// ##
// #.
// 3)
// ..
// #.
// 4)
// ##
// .#
// 5)
// .#
// ##
// 6)
// #.
// ..
// 7)
// .#
// ..
// 8)
// #.
// ##
int is_vertex(char **S, int i , int j)
{
	return (
		(S[i-1][j-1] == '.' && S[i-1][j] == '.' && S[i][j-1] == '.' && S[i][j] == '#') |
		(S[i-1][j-1] == '#' && S[i-1][j] == '#' && S[i][j-1] == '#' && S[i][j] == '.') |
		(S[i-1][j-1] == '.' && S[i-1][j] == '.' && S[i][j-1] == '#' && S[i][j] == '.') |
		(S[i-1][j-1] == '#' && S[i-1][j] == '#' && S[i][j-1] == '.' && S[i][j] == '#') |
		(S[i-1][j-1] == '.' && S[i-1][j] == '#' && S[i][j-1] == '#' && S[i][j] == '#') |
		(S[i-1][j-1] == '#' && S[i-1][j] == '.' && S[i][j-1] == '.' && S[i][j] == '.') |
		(S[i-1][j-1] == '.' && S[i-1][j] == '#' && S[i][j-1] == '.' && S[i][j] == '.') |
		(S[i-1][j-1] == '#' && S[i-1][j] == '.' && S[i][j-1] == '#' && S[i][j] == '#'));
}

int main()
{
	int H, W;
	scanf("%d", &H);
	scanf("%d", &W);
	char **S;
	S = calloc(H, sizeof(char*));
	int ans = 0;
	for (int i = 0; i < H; i++)
	{
		S[i] = calloc(W + 1, sizeof(char));
		scanf("%s", S[i]);
	}
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < W; j++)
//		{
//			printf("%c", S[i][j]);
//		}
//		printf("\n");
//	}
	for (int i = 1; i < H; i++)
	{
		for (int j = 1; j < W; j++)
		{
			ans += is_vertex(S, i, j);
		}
	}
	printf("%d\n", ans);

	return (0);
}
