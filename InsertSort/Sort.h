#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DateType;

//打印数据
void Print(DateType* a, int n);

//直接插入排序
void InsertSort(DateType* a, int n);

//希尔排序
void ShellSort(DateType* a, int n);