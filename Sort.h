#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

void swap(int* p1, int* p2);

void Print(int* array,int n);

//直接插入排序
void InsertSort(int *array,int n);

//希尔排序
void ShellSort(int* a, int n);

//直接选择排序
void SelectSort(int* a, int n);