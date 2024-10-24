#include"Contacts.h"

//ͨѶ¼����Ľ���
ListNode* ListNodeInit(ListNode*p)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (!head)
	{
		printf("�ռ䲻��\n");
		exit(-1);
	}

	//�������һ����ϵ�˵���Ϣ
	ContactInput(head);
	head->next = NULL;

	return head;
}

//ͨѶ¼��������� or �˳�����ϵͳ
void ListNodeDestory(ListNode* con)
{
	//assert(con);
	if (!con)
	{
		printf("error:Delete empty contacts!\n");
		exit(-1);
	}
	printf("�����������ݡ�����\n�ɹ�������\n��ӭ�´�ʹ�ã�");

	ListNode* cur = con->next;
	while (cur)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(con);
}

//��ϵ����Ϣ������
void ContactInput(ListNode* p)
{
	//assert(p);
	if (!p)
	{
		printf("error:Empty contacts!\n");
		exit(-1);
	}
	//����
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

	//�Ա�
	printf("Input sex:(M or W)\n");
	scanf("%c", &(p->_date._sex));
	printf("Your input:%c", p->_date._sex);
	printf("\n");

	//�绰
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

	//��ַ
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

//���ĳ����ϵ����Ϣ
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

//ͨѶ�߽��Ĳ���(β��)
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

//ͨѶ�߽���ɾ��(βɾ)
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

//ͨѶ�߽��Ĳ�ѯ
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

//ͨѶ¼��������
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

//�˵�
void ContactMenu()
{
	printf("********************\n");
	printf("1. ͨѶ¼����Ľ���\n");
	printf("2. ͨѶ�߽��Ĳ���\n");
	printf("3. ͨѶ�߽��Ĳ�ѯ\n");
	printf("4. ͨѶ�߽���ɾ��\n");
	printf("5. ͨѶ¼��������\n");
	printf("0. �˳�����ϵͳ\n");
	printf("********************\n");
}