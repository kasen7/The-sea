#include"Sort.h"

void test_InsertSort()
{
	srand(time(0));
	int a[] = { 9,1,3,5,4,6,8,7,1,5 };
	Print(a, sizeof(a) / sizeof(a[0]));
	int begin = clock();
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	int end = clock();
	printf("time:%d->", end - begin);
	Print(a, sizeof(a) / sizeof(a[0]));
}

void test_ShellSort()
{
	srand(time(0));
	int a[] = { 9,1,3,5,4,6,8,7,1,5 };
	int begin = clock();
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	int end = clock();
	printf("time:%d->", end - begin);
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestOP()
{
	srand(time(0));
	const int N = 10000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	/*
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();*/
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	//printf("HeapSort:%d\n", end4 - begin4);
	//printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
int main()
{
	//test_InsertSort();
	//test_ShellSort();
	TestOP();
	return 0;
}