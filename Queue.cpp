#include"Queue.h"
void QueueInit(Queue* pq)
{
	pq->_head = pq->_tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}

	pq->_head = pq->_tail = NULL;
}

void QueuePush(Queue* pq, QueDateType x)
{
	assert(pq);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (!newNode)
	{
		cout << OVERFLOW;
		exit(-1);
	}

	newNode->_a = x;
	newNode->_next = NULL;
	if (pq->_head == NULL)
	{
		pq->_tail = newNode;
		pq->_head = newNode;
	}
	else
	{
		pq->_tail->_next = newNode;
		pq->_tail = newNode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_head);//�Է�����
	QueueNode* del = pq->_head;
	pq->_head = pq->_head->_next;
	free(del);
}

QueDateType QueueFornt(Queue* pq)
{
	assert(pq);

	return (pq->_head == NULL) ? -1:pq->_head->_a;
}

//���ض�β
QueDateType QueueBack(Queue* pq)
{
	assert(pq);

	return (pq->_tail == NULL) ? -1: pq->_tail->_a;
}

//������Ԫ�ظ���
int QueueNum(Queue* pq)
{
	assert(pq);
	int num = 0;
	QueueNode* cur = pq->_head;
	while (cur)
	{
		num++;
		cur = cur->_next;
	}

	return num;
}

//�������Ƿ�Ϊ��
bool QueueEpoty(Queue* pq)
{
	assert(pq);

	return (pq->_head == NULL) ? 1 : 0;
}