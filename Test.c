#include"Contacts.h"

//void test()
//{
//	ListNode* contacts = NULL;
//	contacts = ListNodeInit(contacts);
//
//	ListNodePrint(contacts);
//
//	char n[] = { "a" };
//	ListNodeFind(contacts, n);
//
//	ListNodePop(contacts);
//	ListNodePrint(contacts);
//
//	ListNodeDestory(contacts);
//	contacts = NULL;
//}
int main()
{
	ContactMenu();
	int input = 1;
	int temp = 1;
	char Name[20] = { 0 };

	ListNode* a = NULL;
	while (input)
	{
		printf("Please select£º");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
		{
			a=ListNodeInit(a);
			break;
		}
		case 2:ListNodePop(a); break;
		case 3:
		{
			char c;
			printf("input name:");
			int i = 0;
			while ((c = getchar()) != EOF)
			{
				if (c != '\n')
				{
					Name[i] = c;
					i++;
				}
			}
			Name[i] = '\0';
			ListNodeFind(a, Name);
			break;
		}
		case 4:ListNodePop(a); break;
		case 5:ListNodePrint(a); break;
		case 0:ListNodeDestory(a); break;
		default:
			printf("Typing error.");
			break;
		}
	}
	return 0;
}