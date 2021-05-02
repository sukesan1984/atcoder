#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_dll t_dll;

struct s_dll
{
	char val;
	t_dll *prev;
	t_dll *next;
};

// 番兵
t_dll *create_new()
{
	t_dll *n;

	n = calloc(1, sizeof(t_dll));
	n->val = 0;
	n->prev = NULL;
	n->next = NULL;
	return n;
}

void insert(t_dll *before, t_dll *after, t_dll *target)
{
	before->next = target;
	after->prev = target;
	target->prev = before;
	target->next = after;
}

void push_back(t_dll *sentinel, char c)
{
	t_dll *n;
	t_dll *last;

	n = create_new();
	n->val = c;

	if (!sentinel->prev)
	{
		sentinel->prev = n;
		sentinel->next = n;
		n->prev = sentinel;
		n->next = sentinel;
	}
	else
	{
		last = sentinel->prev;
		insert(last, sentinel, n);
	}
}

// 最後を削る
// last-prev -> last -> sentinel
void delete_back(t_dll *sentinel)
{
	t_dll *last;

	last = sentinel->prev;
	if (!last)
		return;
	//要素が一つだけの場合
	if (last->prev == sentinel)
	{
		sentinel->prev = NULL;
		sentinel->next = NULL;
	}
	else
	{
		sentinel->prev = last->prev;
		last->prev->next = sentinel;
	}
	free(last);
}

void push_front(t_dll *sentinel, char c)
{
	t_dll *n;
	t_dll *first;

	n = create_new();
	n->val = c;

	if (!sentinel->next)
	{
		sentinel->prev = n;
		sentinel->next = n;
		n->prev = sentinel;
		n->next = sentinel;
	}
	else
	{
		first = sentinel->next;
		insert(sentinel, first, n);
	}
}

void delete_front(t_dll *sentinel)
{
	t_dll *first;

	first = sentinel->next;
	if (!first)
		return;

	if (first->next == sentinel)
	{
		sentinel->prev = NULL;
		sentinel->next = NULL;
	}
	else
	{
		sentinel->next = first->next;
		first->next->prev = sentinel;
	}
	free(first);
}

void show(t_dll *sentinel, int reversed)
{
	t_dll *itr;

	itr = sentinel;
	if (!reversed)
	{
		itr = itr->next;
		while (itr)
		{
			printf("%c", itr->val);
			if (itr->next == sentinel)
				break;
			itr = itr->next;
		}
		printf("\n");
	}
	else
	{
		itr = itr->prev;
		while (itr)
		{
			printf("%c", itr->val);
			if (itr->prev == sentinel)
				break;
			itr = itr->prev;
		}
		printf("\n");
	}
}

int main() {
	int i = 0;
	int len;
	int reversed;
	char *S;
	t_dll *sentinel;
	t_dll *first;
	t_dll *last;
	S = calloc(5 * 100000, sizeof(char));
	scanf("%s", S);
	len = strlen(S);
	reversed = 0;

	sentinel = create_new();
	while (i < len)
	{
		if (S[i] == 'R')
			reversed = (reversed == 0) ? 1 : 0;
		else
		{
			// ひっくり返ってるなら先頭に足す/あるいは先頭を削る
			if (reversed)
			{
				first = sentinel->next;
				// 要素がない時
				if (!first)
					push_front(sentinel, S[i]);
				//同じだった場合
				else if (first->val == S[i])
					delete_front(sentinel);
				else
					push_front(sentinel, S[i]);
			}
			else
			{
				last = sentinel->prev;
				if (!last)
					push_back(sentinel, S[i]);
				else if (last->val == S[i])
					delete_back(sentinel);
				else
					push_back(sentinel, S[i]);
			}
		}
		i++;
	}

	show(sentinel, reversed);
	return (0);
}
