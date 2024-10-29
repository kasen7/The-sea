#include"Heap.h"

void Test()
{
	Heap a;
	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapInit(&a, array, sizeof(array) / sizeof(DateType));
	int x = HeapTop(&a);
	printf("%d ", x);
	HeapPush(&a, 1);
	x = HeapTop(&a);
	printf("%d ", x);
	HeapPop(&a);
	x = HeapTop(&a);
	printf("%d ", x);

	HeapDestory(&a);
}
int main()
{
	Test();
	return 0;
}