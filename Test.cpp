#include"Queue.h"

//void test1()
//{
//	//cout << __cplusplus;
//	//cout << OVERFLOW;
//	Queue q;
//	QueueInit(&q);
//
//	cout << QueueFornt(&q) << endl;
//	QueuePush(&q, 1);
//	cout << QueueFornt(&q) << endl;
//	QueuePop(&q);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePop(&q);
//	cout << QueueFornt(&q) << endl;
//	QueuePush(&q, 4);
//	//while (q._head)
//	//{
//
//	//}
//	QueueDestory(&q);
//}

//void test2()
//{
//	Queue d1;
//	QueueInit(&d1);
//
//	QueuePush(&d1, 2);
//	QueuePush(&d1, 3);
//	QueuePush(&d1, 5);
//
//	cout << QueueFornt(&d1) << endl;
//	QueuePop(&d1);
//	cout << QueueFornt(&d1) << endl;
//	QueuePop(&d1);
//	cout << QueueFornt(&d1) << endl;
//	QueuePop(&d1);
//	cout << QueueFornt(&d1) << endl;
//	QueueDestory(&d1);
//}

void test3()
{
	Queue d2;
	QueueInit(&d2);

	cout << QueueBack(&d2) << endl;
	QueuePush(&d2, 7);
	cout << QueueBack(&d2) << endl;
	//QueuePush(&d2, 11);
	//cout << QueueBack(&d2) << endl;
	//QueuePush(&d2, 13);
	//QueuePush(&d2, 17);
	//cout << QueueBack(&d2) << endl << endl;
	if (QueueEpoty(&d2))
	{
		cout << "NULL Queue";
	}
	cout << QueueNum(&d2);
	QueueDestory(&d2);
}
int main()
{
	test3();
	return 0;
}