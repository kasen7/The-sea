#include"Sort.h"

void swap(int* p1, int* p2)
{
	int* tmp = p1;
	*p1 = *p2;
	*p2 = *tmp;
}

void Print(int* array,int n)
{
	assert(array);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void InsertSort(int* array, int n)
{
	assert(array);

	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = array[end + 1];

		while (end >= 0)
		{
			if (temp < array[end])
			{
				array[end + 1] = array[end];
				end--;
			}
			else
			{
				break;
			}
		}
		array[end + 1] = temp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int temp = a[end + gap];

			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = temp;
			}
		}
	}
}

void SelectSort(int* a, int n)
{
	assert(a);

	int begin = 0;
	int end = n - 1;
	int maxi, mini;
	maxi = mini = 0;

	while (begin <= end)
	{
		for (int i = 0; i < n; ++i)
		{
			if (a[i] > a[maxi])
				maxi = i;

			if (a[i] < a[mini])
				mini = i;
		}

		swap(&a[begin], &a[mini]);
		if (begin==maxi)
		{
			maxi = mini;
		}
		swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}