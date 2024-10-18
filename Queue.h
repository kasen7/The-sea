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

//��ʼ��
void QueueInit(Queue* pq);

//���ٶ���
void QueueDestory(Queue* pq);

//���
void QueuePush(Queue* pq, QueDateType x);

//����
void QueuePop(Queue* pq);

//���ض�ͷ
QueDateType QueueFornt(Queue* pq);

//���ض�β
QueDateType QueueBack(Queue* pq);

//������Ԫ�ظ���
int QueueNum(Queue* pq);

//�������Ƿ�Ϊ��
bool QueueEpoty(Queue* pq);