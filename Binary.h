#include<stdio.h>
#include<stdlib.h>

typedef char BinaryDateType;

typedef struct BinaryTreeNode
{
	BinaryDateType _val;
	struct BinaryTreeNode* _leftChild;
	struct BinaryTreeNode* _rightChild;
}BTNode;

//ǰ�����
void PrevOrder(BTNode* root);

//�������
void InOrder(BTNode* root);

//�������
void PostOrder(BTNode* root);

// �������
void LevelOrder(BTNode* root);

//������
void CreatBinary();