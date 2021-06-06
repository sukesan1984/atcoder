#include <stdio.h>
#include <stdlib.h>

typedef struct	s_ll t_ll;
struct s_ll
{
	int val;
	t_ll *next;
};

t_ll *create_ll(int val)
{
	t_ll *n;

	n = calloc(1, sizeof(t_ll));
	n->val = val;
	n->next = NULL;
	return (n);
}

void append(t_ll **head, int val)
{
	if (*head == NULL)
	{
		*head = create_ll(val);
		return;
	}
	t_ll *itr;
	itr = *head;
	while (itr->next)
	{
		itr = itr->next;
	}
	itr->next = create_ll(val);
}

void show(t_ll *head)
{
	if (!head)
		return;

	while(head)
	{
		printf("->%d\n", head->val);
		head = head->next;
	}
}

// iからスタートした時のパスの数
// visit: 底をすでに通ったかどうか
int solve(int i, int *visit, t_ll **cl)
{
	int ans = 0;
	//すでにそこに通っていた場合
	if (visit[i] == 1)
		return (0);
	// 自分自身で終わる場合で1
	visit[i] = 1;
	ans++;
	t_ll *itr;

	itr = cl[i];
	// iからつながってるところを計算していく
	while (itr)
	{
		ans += solve(itr->val, visit, cl);
		itr = itr->next;
	}
	return (ans);
}

int main()
{
	int N;
	int M;
	scanf("%d", &N);
	scanf("%d", &M);
	int *A;
	int *B;
	t_ll **cl;

	A = calloc(M, sizeof(int));
	B = calloc(M, sizeof(int));
	cl = calloc(N, sizeof(t_ll*));

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &A[i]);
		scanf("%d", &B[i]);
		A[i]--;
		B[i]--;
		append(&(cl[A[i]]), B[i]);
	}

	free(A);
	free(B);
	//int *dp;
	//dp = calloc(N, sizeof(int));
	//for (int i = 0; i < N; i++)
	//{
	//	dp[i] = -1;
	//}
	int ans = 0;
	int each;
	for (int i = 0; i < N; i++)
	{
		int *visit;
		visit = calloc(N, sizeof(int));
		each = solve(i, visit, cl);
		//printf("%d, %d\n", i, each);
		ans += each;
		free(visit);
	}
	free(cl);
	printf("%d\n", ans);

	return (0);
}
