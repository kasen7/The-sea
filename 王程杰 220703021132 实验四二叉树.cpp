#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char BinaryDateType;

typedef struct BinaryTreeNode
{
	BinaryDateType _val;
	struct BinaryTreeNode* _leftChild;
	struct BinaryTreeNode* _rightChild;
}BTNode;

//前序遍历
void PrevOrder(BTNode* root);

//中序遍历
void InOrder(BTNode* root);

//后序遍历
void PostOrder(BTNode* root);

// 层序遍历
void LevelOrder(BTNode* root);

//用递归创造一个二叉树
void InitBinaryTree(BTNode** root);

//销毁树
void DestoryBinaryTree(BTNode** root);

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

//层序遍历所需队列函数
typedef BTNode* QueDateType;

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

void test1()
{
	BTNode* tree = NULL;
	InitBinaryTree(&tree);

	PrevOrder(tree);
	LevelOrder(tree);
	DestoryBinaryTree(&tree);
}
int main()
{
	/*CreatBinary();*/
	test1();
	return 0;
}
