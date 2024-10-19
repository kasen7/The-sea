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

//创建一个节点
SLNode* BuySLN(SLNDateType x);

//尾增
void SLNPushBack(SLNode** s, SLNDateType x);

//打印单链表
void SLNPrint(SLNode* s);

//尾删
void SLNPopBack(SLNode** s);

//头增
void SLNPushFront(SLNode** s, SLNDateType x);

//头删
void SLNPopFront(SLNode** s);

//插入
void SLNInsertAfter(SLNode* pos, SLNDateType x);

//查找并查改
void SLNFind(SLNode** s, SLNDateType x, SLNDateType nx);

//销毁链表
void SLNDestory(SLNode** s);