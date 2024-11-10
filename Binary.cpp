#include"Binary.h"

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->_val);
	PrevOrder(root->_leftChild);
	PrevOrder(root->_rightChild);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->_leftChild);
	printf("%c ", root->_val);
	InOrder(root->_rightChild);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->_leftChild);
	PostOrder(root->_rightChild);
	printf("%c ", root->_val);
}

//层序遍历所需函数

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
	assert(pq->_head);//以防空列
	QueueNode* del = pq->_head;
	pq->_head = pq->_head->_next;
	free(del);
}

QueDateType QueueFornt(Queue* pq)
{
	assert(pq);

	return (pq->_head == NULL) ? NULL : pq->_head->_a;
}

bool QueueEpoty(Queue* pq)
{
	assert(pq);

	return (pq->_head == NULL) ? 1 : 0;
}
void LevelOrder(BTNode* root)
{
	Queue a;
	QueueInit(&a);

	if (root == NULL)
		return;

	QueuePush(&a, root);
	while (!QueueEpoty(&a))
	{
		BTNode* front = QueueFornt(&a);
		QueuePop(&a);

		printf("%c ", front->_val);

		if (front->_leftChild)
		{
			QueuePush(&a, front->_leftChild);
		}
		if (front->_rightChild)
		{
			QueuePush(&a, front->_rightChild);
		}
	}

	QueueDestory(&a);
}

void CreatBinary()
{
	BTNode nod1;
	BTNode nod2;
	BTNode nod3;
	BTNode nod4;
	BTNode nod5;
	BTNode nod6;

	nod1._val = 'A';
	nod2._val = 'B';
	nod3._val = 'C';
	nod4._val = 'D';
	nod5._val = 'E';
	nod6._val = 'F';

	nod1._leftChild = &nod2;
	nod1._rightChild = &nod3;
	nod2._leftChild = &nod4;
	nod2._rightChild = &nod5;
	nod4._leftChild = nod4._rightChild = NULL;
	nod5._leftChild = nod5._rightChild = NULL;
	nod3._leftChild = &nod6;
	nod3._rightChild = NULL;
	nod6._leftChild = nod6._rightChild = NULL;

	PrevOrder(&nod1);
	printf("\n");
	InOrder(&nod1);
	printf("\n");
	PostOrder(&nod1);
	printf("\n");
	printf("\n");

	BTNode* test1 = BinaryTreeFind(&nod1, 'E');
	if (test1)
		printf("%c ", test1->_val);

	printf("\n \n");

	int num = BinaryTreeLevelKsize(&nod1, 3);
	printf("%d ", num);
}

BTNode* BinaryTreeFind(BTNode* root, BinaryDateType x)
{
	if (root == NULL)
		return NULL;

	if (root->_val == x)
		return root;

	BTNode* node = BinaryTreeFind(root->_leftChild, x);

	if (node)
		return node;
	
	node = BinaryTreeFind(root->_rightChild, x);

	if (node)
		return node;

	return NULL;
}

int BinaryTreeLevelKsize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKsize(root->_leftChild, k - 1) + BinaryTreeLevelKsize(root->_rightChild, k-1);
}

void InitBinaryTree(BTNode** root)
{
	BinaryDateType x;
	printf("input date:(input '#' over.)\n");
	scanf("%c", &x);
	getchar();
	if (x == '#')
	{
		*root = NULL;
		return;
	}

	*root = (BTNode*)malloc(sizeof(BTNode));
	if (!(*root))
	{
		printf("error:InitBinarryTree malloc!");
		exit(-1);
	}

	(*root)->_val = x;
	InitBinaryTree(&(*root)->_leftChild);
	InitBinaryTree(&(*root)->_rightChild);
}

void DestoryBinaryTree(BTNode** root)
{
	if (*root == NULL)
		return;

	DestoryBinaryTree(&(*root)->_leftChild);
	DestoryBinaryTree(&(*root)->_rightChild);
	free(*root);
}