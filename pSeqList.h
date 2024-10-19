#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

typedef int SLNDateType;

typedef struct SeqListNode
{
	SLNDateType date;
	struct SeqListNode* next;
}SLNode;

//����һ���ڵ�
SLNode* BuySLN(SLNDateType x);

//β��
void SLNPushBack(SLNode** s, SLNDateType x);

//��ӡ������
void SLNPrint(SLNode* s);

//βɾ
void SLNPopBack(SLNode** s);

//ͷ��
void SLNPushFront(SLNode** s, SLNDateType x);

//ͷɾ
void SLNPopFront(SLNode** s);

//����
void SLNInsertAfter(SLNode* pos, SLNDateType x);

//���Ҳ����
void SLNFind(SLNode** s, SLNDateType x, SLNDateType nx);

//��������
void SLNDestory(SLNode** s);