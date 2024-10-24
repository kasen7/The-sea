#define _CRT_SECURE_NO_WARNINGS
#pragma once
//C语言版本
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

//通讯录链表的建立
ListNode* ListNodeInit(ListNode* p);

//通讯录链表的销毁 or 退出管理系统
void ListNodeDestory(ListNode* con);

//通讯者结点的插入(尾插)
void ListNodePush(ListNode* con);

//通讯者结点的查询
void ListNodeFind(ListNode* con, char name[]);

//通讯者结点的删除(尾删)
void ListNodePop(ListNode* con);

//通讯录链表的输出
void ListNodePrint(ListNode* con);

//联系人信息的输入
void ContactInput(ListNode* p);

//输出某个联系人信息
void ContactPrint(ListNode* p);

//菜单
void ContactMenu();