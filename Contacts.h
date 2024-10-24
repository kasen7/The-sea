#define _CRT_SECURE_NO_WARNINGS
#pragma once
//C���԰汾
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct Contact
{
	char _name[20];
	char _sex;
	int _phone[13];
	char _addr[31];
}Contact;

typedef struct ListNode
{
	Contact _date;
	struct ListNode* next;
}ListNode;

//ͨѶ¼����Ľ���
ListNode* ListNodeInit(ListNode* p);

//ͨѶ¼��������� or �˳�����ϵͳ
void ListNodeDestory(ListNode* con);

//ͨѶ�߽��Ĳ���(β��)
void ListNodePush(ListNode* con);

//ͨѶ�߽��Ĳ�ѯ
void ListNodeFind(ListNode* con, char name[]);

//ͨѶ�߽���ɾ��(βɾ)
void ListNodePop(ListNode* con);

//ͨѶ¼��������
void ListNodePrint(ListNode* con);

//��ϵ����Ϣ������
void ContactInput(ListNode* p);

//���ĳ����ϵ����Ϣ
void ContactPrint(ListNode* p);

//�˵�
void ContactMenu();