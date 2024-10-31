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

void LevelOrder(BTNode* root)
{

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
}