#include"pSeqList.h"

//void testSLN1()
//{
	//SLNode* s = NULL;

	//SLNPushBack(&s, 1);
	//SLNPushBack(&s, 2);
	//SLNPushBack(&s, 3);
	//SLNPushBack(&s, 4);
	//SLNPrint(s);

	////SLNPopBack(&s);
	////SLNPopBack(&s);
	////SLNPopBack(&s);
	////SLNPopBack(&s);
	////SLNPrint(s);

	////SLNPopBack(&s);
	////SLNPrint(s);

	//SLNPushFront(&s, 666);
	//SLNPushFront(&s, 999);
	//SLNPrint(s);

//	SLNInsertAfter(s, 5);
//	SLNPrint(s);
//}

//void test2()
//{
//	SLNode* s = NULL;
//
//	SLNPushBack(&s, 1);
//	SLNPushBack(&s, 2);
//	SLNPushBack(&s, 3);
//	SLNPushBack(&s, 4);
//	SLNPrint(s);
//
//	SLNFind(&s, 3,99);
//	SLNPrint(s);
//}

void test3()
{
	SLNode* s=NULL;
	SLNPushBack(&s, 12);
	SLNPushBack(&s, 23);
	SLNPushBack(&s, 46);
	SLNPushBack(&s, 67);
	SLNPushBack(&s, 85);
	SLNPrint(s);
}
int main()
{
//	testSLN1();

//	test2();
	test3();
	return 0;
}