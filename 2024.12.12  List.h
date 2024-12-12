#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DateType;

typedef struct ListNode
{
	DateType _val;
	ListNode* _next;
	ListNode* _prev;
}ListNode;

//生成新节点
ListNode* BuyNode(DateType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_val = x;
	newNode->_next = NULL;
	newNode->_prev = NULL;

	return newNode;
}

//创造头节点
ListNode* CreateList(ListNode* phead)
{
	ListNode* head = BuyNode(INT_MAX);
	head->_next = head;
	head->_prev = head;

	return head;
}

void Push_back(ListNode* phead,DateType x)
{
	assert(phead);
	if (phead->_next == phead)
	{
		ListNode* newNode = BuyNode(x);
		newNode->_next = phead;
		newNode->_prev = phead;
		phead->_next = newNode;
		phead->_prev = newNode;
	}
	else
	{
		//找尾
		ListNode* tail = phead->_next;
		while (tail->_next != phead)
		{
			tail = tail->_next;
		}

		ListNode* newNode = BuyNode(x);
		tail->_next = newNode;
		newNode->_prev = tail;

		newNode->_next = phead;
		phead->_prev = newNode;
	}
}

void Pop_back(ListNode* phead)
{
	assert(phead);

	ListNode* tail = phead->_next;
	ListNode* prev = phead;
	while (tail->_next != phead)
	{
		prev = tail;
		tail = tail->_next;
	}

	//头节点不删
	if (tail != phead)
	{
		free(tail);
		tail = NULL;

		prev->_next = phead;
		phead->_prev = prev;
	}
}

void Push_front(ListNode* phead, DateType x)
{
	assert(phead);

	ListNode* first = phead->_next;
	ListNode* newNode = BuyNode(x);
	
	phead->_next = newNode;
	newNode->_prev = phead;

	newNode->_next = first;
	first->_prev = newNode;

}

void Pop_front(ListNode* phead)
{
	assert(phead);

	ListNode* sec = phead->_next->_next;
	ListNode* fir = phead->_next;

	//头节点不删
	if (sec != fir)
	{
		free(fir);

		phead->_next = sec;
		sec->_prev = phead;
	}
}

void Print_List(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->_next;
	printf("head ->");
	while (cur != phead)
	{
		printf("%d ->", cur->_val);
		cur = cur->_next;
	}
	printf("head\n");
}

ListNode* Find(ListNode* phead, DateType val)
{
	assert(phead);

	ListNode* cur = phead->_next;
	while (cur != phead)
	{
		if (cur->_val == val)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void InsertBack(ListNode* pos, DateType x)
{
	assert(pos);

	ListNode* next = pos->_next;
	ListNode* newNode = BuyNode(x);

	pos->_next = newNode;
	newNode->_prev = pos;

	newNode->_next = next;
	next->_prev = newNode;
}

void InsertFront(ListNode* pos, DateType x)
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* newNode = BuyNode(x);

	//防止只有头节点
	if (prev == pos )
	{
		InsertBack(pos, x);
	}
	else
	{
		pos->_prev = newNode;
		newNode->_next = pos;

		newNode->_prev = prev;
		prev->_next = newNode;
	}
}

void Erase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	//防止删除头节点
	if (prev != next)
	{
		free(pos);

		prev->_next = next;
		next->_prev = prev;
	}
}

//这两个和Print_List配合着用有反而画蛇添足
////返回第一个节点
//ListNode* begin(ListNode* phead)
//{
//	return phead->_next;
//}
//
////返回最后一个节点
//ListNode* end(ListNode* phead)
//{
//	return phead->_prev;
//}

//销毁链表
void Destory(ListNode* phead)
{
	if (phead == NULL)
		return;

	ListNode* cur = phead->_next;
	while (cur->_next != phead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}

	//这里free掉phead后本应置空，但这是一级指针没法传到外面
	free(phead);
}
