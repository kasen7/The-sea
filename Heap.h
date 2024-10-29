#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int DateType;

typedef struct Heap
{
	DateType* php;
	int _size;
	int _capacity;
}Heap;

//初始化堆
void HeapInit(Heap* ph, DateType* a, int n);

//释放堆
void HeapDestory(Heap* ph);

//入堆
void HeapPush(Heap* ph, DateType x);

//出堆（出首根）
void HeapPop(Heap* ph);

//向下调整
void AdjustDown(int* a, int n, int root);

//向上调整
void AdjustUp(int* a, int n, int child);

void Swap(DateType* a, DateType* b);

//建堆
void HeapSort(DateType* a, int n);

//输出堆首
DateType HeapTop(Heap* ph);