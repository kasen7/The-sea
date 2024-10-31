#include<stdio.h>
#include<stdlib.h>

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

//创造树
void CreatBinary();