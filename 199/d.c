#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_ll t_ll;

struct s_ll {
	int vertex;
	t_ll *next;
};

typedef struct s_vertex_info
{
	int vertex;
	int visit; // 0: 未探索, 1: 発見, 2: 探索済み
	int color; // 0: 赤, 1: 緑, 2: 青
} t_vertex_info;

void append(t_ll **head, int vertex)
{
	t_ll *n;
	t_ll *cur;

	n = calloc(1, sizeof(t_ll));
	n->vertex = vertex;
	n->next = NULL;
	// 空なら生成して代入する
	if (*head == NULL)
		*head = n;
	else
	{
		//最後に突っ込む
		cur = *head;
		while(cur->next)
			cur = cur->next;
		cur->next = n;
	}
}

void show_ll(t_ll *list)
{
	printf("[");
	while(list)
	{
		printf("%d, ", list->vertex);
		list = list->next;
	}
	printf("NULL]\n");
}

void show_adjancy_list(t_ll **adjancy_list, int N)
{
	t_ll *cur;
	for (int i = 0; i < N; i++)
	{
		printf("vertex: %d: \n ", i + 1);
		if (!adjancy_list[i])
		{
			printf("NULL\n");
			continue;
		}
		// 隣接頂点の表示
		printf(" adjancy: ");
		if (adjancy_list[i])
		{
			cur = adjancy_list[i];
			while(cur)
			{
				printf("%d, ", cur->vertex + 1);
				cur = cur->next;
			}
		}
		printf("NULL\n");
	}
}

void reset_vi(t_vertex_info **vi, int N, int pattern)
{
	for (int i = 0; i < N; i++)
	{
		vi[i]->visit = 0;
		// 赤のところはbitが立ってる
		if (1 & pattern >> i)
			vi[i]->color = 0;
		else
			vi[i]->color = -1;
	}
}

void show_vi(t_vertex_info **vi, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("[%2d]", vi[i]->color);
	}
	//printf("\n");
}

int walk(t_vertex_info **vi, t_ll **adjancy_list, int *visit, int vertex, int cnt, int call_directly)
{
	t_ll *cur;

	if (visit[vertex] == 1)
		return cnt;
	if ((vi[vertex]->color == 1 || vi[vertex]->color == 2))
	{
		if (call_directly)
			cnt = 1;
	}
	else if (vi[vertex]->color == -1)
		cnt++;
	else
	{
		visit[vertex] = 1;
		return cnt;
	}
	visit[vertex] = 1;
	cur = adjancy_list[vertex];
	while (cur)
	{
		cnt = walk(vi, adjancy_list, visit, cur->vertex, cnt, 0);
		cur = cur->next;
	}
	return cnt;
}

// 隣接リスト集合から、連結成分数を取得する
int count_adjancy_count(t_vertex_info **vi, t_ll **adjancy_list, int N)
{
	int *visit;
	int s;

	s = 0;
	visit = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
		s += walk(vi, adjancy_list, visit, i, 0, 1);
	free(visit);
	return (s);
}

// 無色のところを順番に塗っていく (invalidな時は 0)を返す
int is_bipartite_graph(t_vertex_info **vi, t_ll **adjancy_list, int vertex, int color)
{
	t_ll *cur;
	// 無色じゃなければ何もしない
	if (vi[vertex]->color != -1)
		return (1);

	// 無色だったら塗る
	vi[vertex]->color = color;
	cur = adjancy_list[vertex];
	while (cur)
	{
		if (vi[cur->vertex]->color == color)
			return (0);
		if (vi[cur->vertex]->color == -1 && !is_bipartite_graph(vi, adjancy_list, cur->vertex, (color == 1) ? 2 : 1))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int valid_coloring(t_vertex_info **vi, t_ll **adjancy_list, int N)
{
	int res;
	for (int i = 0; i < N; i++)
	{
		res = is_bipartite_graph(vi, adjancy_list, i, 1);
		if (!res)
			return (0);
	}
	return (1);
}

int main()
{
	int N;
	int M;
	int *A;
	int *B;
	int red_count;
	int res;
	unsigned long long ans;
	t_ll **adjancy_list; // 隣接リスト集合
	t_vertex_info **vi;

	scanf("%d", &N);
	//if (N == 1)
	//{
	//	printf("%d\n", 3);
	//	return (0);
	//}

	adjancy_list = calloc(N, sizeof(t_ll*));
	for (int i = 0; i < N; i++)
	{
		adjancy_list[i] = NULL;
	}

	scanf("%d", &M);
	A = calloc(M, sizeof(int));
	B = calloc(M, sizeof(int));

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &A[i]);
		scanf("%d", &B[i]);
		A[i] = A[i] - 1;
		B[i] = B[i] - 1;
		append(&adjancy_list[A[i]], B[i]);
		append(&adjancy_list[B[i]], A[i]);
	}
	// 隣接リストができた
	//show_adjancy_list(adjancy_list, N);


	// 赤で決め打ちで塗る（全探索）
	red_count = 1 << N;
	vi = calloc(N, sizeof(t_vertex_info*));
	for (int i = 0; i < N; i++)
	{
		vi[i] = calloc(1, sizeof(t_vertex_info));
		vi[i]->vertex = i;
	}
	ans = 0;
	//printf("red_count: %d\n", red_count);
	int s;

	int count = 0;
	int ng = 0;
	for (int i = 0; i < red_count; i++)
	{
		ng = 0;
		//printf("%d reset\n", i);
		// 赤で初期化する
		reset_vi(vi, N, i);
		// 赤が隣り合ってないかチェックする
		for (int j = 0; j < M; j++)
		{
			if (vi[A[j]]->color == 0 && vi[B[j]]->color == 0)
			{
				ng = 1;
				break;
			}
		}
		if (ng)
			continue;
		if (valid_coloring(vi, adjancy_list, N))
		{
			//show_vi(vi, N);
			//printf(" [ok]\n");
			count++;
			s = count_adjancy_count(vi, adjancy_list, N);
			//show_vi(vi, N);
			//printf(" s: %d\n", s);
			ans += (1 << s);
		}
	}
	//printf("count: %d\n", count);
	printf("%lld\n", ans);

	return (0);
}
