#include"Heap.h"

void HeapSort(DateType* a, int n)
{
	assert(a);
	//构建堆
	//从底部叶子节点开始向下调整，一路往上，最后将整棵树调完整
	//准确说应该从最后一个父节点向上调整，故（n-1）后再-1 /2，求最后一个父节点
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
}

void HeapInit(Heap* ph, DateType* a, int n)
{
	ph->php = (DateType*)malloc(sizeof(DateType) * n);
	if (!ph->php)exit(-1);

	memcpy(ph->php, a, sizeof(DateType) * n);
	ph->_size = ph->_capacity = n;

	HeapSort(ph->php, n);
}

void HeapDestory(Heap* ph)
{
	assert(ph);

	free(ph->php);
	ph->php = NULL;

	ph->_capacity = ph->_size = 0;
}

void HeapPush(Heap* ph, DateType x)
{
	assert(ph);

	if (ph->_size == ph->_capacity)
	{
		ph->_capacity *= 2;
		DateType* temp = (DateType*)realloc(ph->php, sizeof(DateType) * ph->_capacity);
		if (!temp)exit(-1);

		ph->php = temp;
	}

	ph->php[ph->_size++] = x;
	AdjustUp(ph->php, ph->_size, ph->_size-1);
}

void AdjustDown(int* a,int n,int root)
{
	assert(a);

	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child+1 < n && a[child + 1]< a[child])
		{
			child++;
		}

		if ( a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUp(int* a, int n, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent= (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void Swap(DateType* a, DateType* b)
{
	DateType temp = *a;
	*a = *b;
	*b = temp;
}

void HeapPop(Heap* ph)
{
	assert(ph);
	assert(ph->_size > 0);
	Swap(&ph->php[0], &ph->php[ph->_size - 1]);
	ph->_size--;
	AdjustDown(ph->php, ph->_size, 0);
}

DateType HeapTop(Heap* ph)
{
	assert(ph);

	return ph->php[0];
}