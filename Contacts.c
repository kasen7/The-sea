#include"Contacts.h"

//通讯录链表的建立
ListNode* ListNodeInit(ListNode*p)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (!head)
	{
		printf("空间不足\n");
		exit(-1);
	}

	//并输入第一个联系人的信息
	ContactInput(head);
	head->next = NULL;

	return head;
}

//通讯录链表的销毁 or 退出管理系统
void ListNodeDestory(ListNode* con)
{
	//assert(con);
	if (!con)
	{
		printf("error:Delete empty contacts!\n");
		exit(-1);
	}
	printf("正在销毁数据。。。\n成功。。。\n欢迎下次使用！");

	ListNode* cur = con->next;
	while (cur)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(con);
}

//联系人信息的输入
void ContactInput(ListNode* p)
{
	//assert(p);
	if (!p)
	{
		printf("error:Empty contacts!\n");
		exit(-1);
	}
	//姓名
	printf("Input name:(input ctrl+z and enter to finish)\n");
	char c;
	int i = 0;
	while ((c = getchar()) != EOF)
	{
		if (c != '\n')
		{
			p->_date._name[i] = c;
			i++;
		}
	}
	p->_date._name[i] = '\0';
	
	printf("Your input:%s", p->_date._name);
	printf("\n");

	//性别
	printf("Input sex:(M or W)\n");
	scanf("%c", &(p->_date._sex));
	printf("Your input:%c", p->_date._sex);
	printf("\n");

	//电话
	printf("Input phone:(input -1 to finish)\n");
	i = 0;
	int input = 1;
	while (input)
	{
		scanf("%d", &input);
		p->_date._phone[i] = input;
		if (input == -1)
			break;
		i++;
	}
	printf("Your input:");
	for(int j=0;j<i;j++)
	{
		printf("%d ", p->_date._phone[j]);
	}
	printf("\n");

	//地址
	printf("Input addr:(input ctrl+z and enter to finish)\n");
	i = 0;
	while ((c = getchar()) != EOF)
	{
		if (c != '\n')
		{
			p->_date._addr[i] = c;
			i++;
		}
	}
	p->_date._addr[i] = '\0';

	printf("Your input:%s", p->_date._addr);
	printf("\n");
}

//输出某个联系人信息
void ContactPrint(ListNode* p)
{
	//assert(p);
	if (!p)
	{
		printf("error:Empty contacts!\n");
		exit(-1);
	}
	if (p->_date._sex == 'e')
	{
		printf("null contact\n");
		exit(-1);
	}
	ListNode* cur = p;
	printf("name:%s\n", cur->_date._name);

	printf("sex:%c\n", cur->_date._sex);

	printf("phone:");
	for (int i= 0; cur->_date._phone[i] != -1; ++i)
	{
		printf("%d ", cur->_date._phone[i]);
	}
	printf("\n");

	printf("addr:%s\n", cur->_date._addr);
}

//通讯者结点的插入(尾插)
void ListNodePush(ListNode* con)
{
	//assert(con);
	if (!con)
	{
		printf("error:Empty contacts!\n");
		exit(-1);
	}
	ListNode* tail = con;
	while (tail->next)
	{
		tail = tail->next;
	}

	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);

	ContactInput(newNode);

	tail->next = newNode;
	newNode->next = NULL;
}

//通讯者结点的删除(尾删)
void ListNodePop(ListNode* con)
{
	//assert(con);
	if (!con)
	{
		printf("error:Empty contacts!\n");
		exit(-1);
	}
	ListNode* tail = con;
	ListNode* cur = tail;
	while (tail->next)
	{
		cur = tail;
		tail = tail->next;
	}

	free(tail);
	if (con == cur)
	{
		con->_date._sex = 'e';
	}
	cur->next = NULL;
}

//通讯者结点的查询
void ListNodeFind(ListNode* con, char name[])
{
	//assert(con);
	if (!con)
	{
		printf("error:Empty contacts!\n");
		exit(-1);
	}
	ListNode* cur = con;
	int tem = 1;
	while (cur)
	{
		if (cur->_date._name == name)
		{
			printf("Yes!Information is:\n");
			ContactInput(cur);
			tem = 0;
			break;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (tem == 1)
		printf("NO!There is no such contact.\n");
}

//通讯录链表的输出
void ListNodePrint(ListNode* con)
{
	//assert(con);
	if (!con)
	{
		printf("error:Empty contacts!\n");
		exit(-1);
	}
	ListNode* cur = con;

	while (cur)
	{
		ContactPrint(cur);
		cur = cur->next;
	}
}

//菜单
void ContactMenu()
{
	printf("********************\n");
	printf("1. 通讯录链表的建立\n");
	printf("2. 通讯者结点的插入\n");
	printf("3. 通讯者结点的查询\n");
	printf("4. 通讯者结点的删除\n");
	printf("5. 通讯录链表的输出\n");
	printf("0. 退出管理系统\n");
	printf("********************\n");
}