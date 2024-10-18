#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

typedef int QueDateType;

typedef struct QueueNode
{
	QueDateType _a;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

//初始化
void QueueInit(Queue* pq);

//销毁队列
void QueueDestory(Queue* pq);

//入队
void QueuePush(Queue* pq, QueDateType x);

//出队
void QueuePop(Queue* pq);

//返回队头
QueDateType QueueFornt(Queue* pq);

//返回队尾
QueDateType QueueBack(Queue* pq);

//队列中元素个数
int QueueNum(Queue* pq);

//检测队列是否为空
bool QueueEpoty(Queue* pq);