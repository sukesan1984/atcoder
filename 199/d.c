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

int walk(t_vertex_info **vi, t_ll **adjancy_list, int *visit, int vertex, int s, int first)
{
	int res;
	t_ll *cur;

	if (visit[vertex])
		return 0;
	if (vi[vertex]->color == -1)
		s++;
	else if (vi[vertex]->color != 0 && first)
	{
		s++;
		first = 0;
	}
	visit[vertex] = 1;
	cur = adjancy_list[vertex];
	while (cur)
	{
		res = walk(vi, adjancy_list, visit, cur->vertex, s, first);
		if (res >= 1)
			s = res;
		cur = cur->next;
	}
	return s;
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

// 無色のところを順番に塗っていく (invalidな時は -1)を返す
int color_recursive(t_vertex_info **vi, t_ll **adjancy_list, int vertex, int caller_vertex)
{
	t_ll *cur;

	//一度訪れていて、色が決まってるときはSKIP
	if (vi[vertex]->visit && vi[vertex]->color != -1)
	{
		if (caller_vertex != -1 && vi[caller_vertex]->color == vi[vertex]->color)
			return -1;
		return (0);
	}

	vi[vertex]->visit = 1;
	// 自分自身の色を決める
	if (caller_vertex != -1)
	{
		// 隣が赤だったら自分は
		if (vi[caller_vertex]->color == 0)
		{
			//呼び出し元が赤で、自分も赤だったらだめ
			if (vi[vertex]->color == 0)
				return -1;
		}
		else if (vi[caller_vertex]->color == -1)
		{
			// 呼び出し元 -1
			if (vi[vertex]->color == -1)
			{
				vi[caller_vertex]->color = 1;
				vi[vertex]->color = 2;
			}
			else if (vi[vertex]->color != 0)
				vi[caller_vertex]->color = (vi[vertex]->color == 1) ? 2 : 1;
		}
		else
		{
			// こういうぬりかたはできない
			if (vi[vertex]->color == vi[caller_vertex]->color)
				return -1;
			else if (vi[vertex]->color == -1)
				vi[vertex]->color = (vi[caller_vertex]->color == 1) ? 2 : 1;
		}
	}
	int res;
	cur = adjancy_list[vertex];
	while (cur)
	{
		res = color_recursive(vi, adjancy_list, cur->vertex, vertex);
		if (res == -1)
			return (res);
		cur = cur->next;
	}
	return (0);
}

int is_bipartite_graph(t_vertex_info **vi, t_ll **adjancy_list, int N)
{
	int res;
	for (int i = 0; i < N; i++)
	{
		res = color_recursive(vi, adjancy_list, i, -1);
		if (res == -1)
			return (0);
	}
	//show_vi(vi, N);
	//printf("\n");
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
	for (int i = 0; i < red_count; i++)
	{
		//printf("%d reset\n", i);
		// 赤で初期化する
		reset_vi(vi, N, i);
		if (is_bipartite_graph(vi, adjancy_list, N))
		{
			//show_vi(vi, N);
			//printf(" [ok]\n");
			//count++;
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
