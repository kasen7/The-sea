#include"pSeqList.h"

SLNode* BuySLN(SLNDateType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (!newnode)
	{
		perror("malloc:error!");
		exit(-1);
	}
	newnode->date = x;
	newnode->next = NULL;

	return newnode;
}

void SLNPushBack(SLNode** head, SLNDateType x)
{
	SLNode* newNode = BuySLN(x);
	if (!*head)
	{
		*head = newNode;
	}
	else
	{
		SLNode* tail=*head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
	
		tail->next = newNode;
	}	
}

void SLNPrint(SLNode* head)
{
	if (head == NULL)
	{
		cout << "NULL" << endl;
		return;
	}

	SLNode* cur = head;
	while (cur)
	{
		cout << cur->date << "->";
		cur = cur->next;
	}
	cout << "NULL" << endl;
}

void SLNPopBack(SLNode** s)
{
	if (*s == NULL)
	{
		return;
	}
	else
	{
		SLNode* tail = *s;
		SLNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		if (prev == NULL)
		{
			*s = NULL;
		}
		free(tail);
		if(prev!=NULL)
			prev->next = NULL;
	}
}

void SLNPushFront(SLNode** s, SLNDateType x)
{
	SLNode* newnode = BuySLN(x);
	if (*s == NULL)
	{
		*s = newnode;
	}
	else
	{
		newnode->next = *s;
		*s = newnode;
	}
}

void SLNPopFront(SLNode** s)
{
	if (*s == NULL)
	{
		return;
	}
	else
	{
		SLNode* newnode = *s;
		*s = (*s)->next;
		free(newnode);
	}
}

void SLNInsertAfter(SLNode* pos, SLNDateType x)
{
	assert(pos);
	SLNode* newnode = BuySLN(x);

	newnode->next = pos->next;
	pos->next = newnode;
}

void SLNFind(SLNode** s, SLNDateType x, SLNDateType nx)
{
	if (*s == NULL)
	{
		return;
	}
	else
	{
		SLNode* tail = *s;

		while (tail->date != x)
		{
			tail = tail->next;
		}

		if (tail->date == x)
		{
			cout << "YES!" << endl;
			tail->date = nx;
		}
		else
		{
			cout << "NO Find!" << endl;
		}
	}
}

void SLNDestory(SLNode** s)
{
	assert(*s);

	SLNode* tail = *s;
	while (tail->next != NULL)
	{
		SLNode* curNext = tail->next;
		free(tail);
		tail = curNext;
	}
	free(tail);
	*s = NULL;
}