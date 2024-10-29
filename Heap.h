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

//��ʼ����
void HeapInit(Heap* ph, DateType* a, int n);

//�ͷŶ�
void HeapDestory(Heap* ph);

//���
void HeapPush(Heap* ph, DateType x);

//���ѣ����׸���
void HeapPop(Heap* ph);

//���µ���
void AdjustDown(int* a, int n, int root);

//���ϵ���
void AdjustUp(int* a, int n, int child);

void Swap(DateType* a, DateType* b);

//����
void HeapSort(DateType* a, int n);

//�������
DateType HeapTop(Heap* ph);