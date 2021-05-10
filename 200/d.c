#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_ll t_ll;
struct s_ll
{
	int val;
	t_ll *next;
};

void append(t_ll **head, int val)
{
	t_ll *n;
	t_ll *itr;
	n = calloc(1, sizeof(t_ll));
	n->val = val;
	n->next = NULL;

	if (*head == NULL)
	{
		*head = n;
		return;
	}

	itr = *head;
	while (itr->next)
	{
		itr = itr->next;
	}
	itr->next = n;
}

void show_ll(t_ll *head)
{
	while (head)
	{
		printf(" %d", head->val + 1);
		head = head->next;
	}
}

void show_kumiawase(int i, int N)
{
	t_ll head;
	int count = 0;

	head.next = NULL;
	for (int k = 0; k < N; k++)
	{
		if (i >> k & 1)
		{
			append(&(head.next), k);
			count++;
		}
	}
	printf("%d", count);
	show_ll(head.next);
	printf("\n");
	free(head.next);
}

int main()
{
	int N;
	scanf("%d", &N);
	int *A;
	int kumiawase[200];
	for (int i = 0; i < 200; i++)
	{
		kumiawase[i] = 0;
	}

	A = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	int kumi_max = (N >= 8) ? 201 : pow((double)2, (double)N);

	for (int i = 0; i < kumi_max; i++)
	{
		//printf("cand: %d\n", i);
		int sum = 0;
		for (int k = 0; k < N; k++)
		{
			if (i >> k & 1)
			{
				sum = (sum + (A[k] % 200)) % 200;
			}
		}

		// この場合、組み合わせが存在する
		//printf("sum: %d, kumiawase[sum]: %d\n", sum, kumiawase[sum]);
		if (kumiawase[sum] > 0)
		{
			printf("Yes\n");
			show_kumiawase(i, N);
			show_kumiawase(kumiawase[sum], N);
			return (0);
		}
		// 存在しない場合は、その組み合わせをセットしておく
		else
		{
			kumiawase[sum] = i;
		}
	}
	printf("No\n");
	return (0);
}
