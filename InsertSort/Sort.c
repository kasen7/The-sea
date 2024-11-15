#include"Sort.h"
void Print(DateType* a, int n)
{
	assert(a);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(DateType* a, int n)
{
	assert(a);
//这是排一次序
	//int end = 0;//end为有序 序列的最后一个下标
	//int temp= a[end + 1];//temp始终为无序序列第一个


	//while (end >= 0)
	//{
	//	if (temp < a[end])
	//	{
	//		a[end + 1] = a[end];
	//		end--;
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
	//a[end] = temp;

//完整直接插入排序
	//比特课上代码
	for(int i= 0;i< n-1;++i)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end+1] = temp;
	}

	//自想代码 _效率贼低
	//int num = 0;
	//int end = 0;
	//while (end < n - 1)
	//{
	//	int temp = a[end + 1];
	//	while (end >= 0)
	//	{
	//		if (temp < a[end])
	//		{
	//			a[end + 1] = a[end];
	//			end--;
	//		}
	//		else
	//		{
	//			break;
	//		}
	//	}
	//	a[end + 1] = temp;
	//	end++;
	//	printf("%d\n", num++);
	//	Print(a, n);
	//}
}

void ShellSort(DateType* a, int n)
{
	assert(a);
//单趟排序
	//int gap = 3;
	//for (int i = 0; i < n - gap; i++)
	//{
	//	int end = i;
	//	int temp = a[end + gap];
	//	while (end >= 0)
	//	{
	//		if (temp < a[end])
	//		{
	//			a[end + gap] = a[end];
	//			end-= gap;
	//		}
	//		else
	//		{
	//			break;
	//		}
	//	}
	//	a[end + gap] = temp;
	//}

//完整希尔排序
	//希尔排序分两步：
	//1.预排序：将数组中大的数往后挪，小的数往前挪；
	//2.直接插入排序，由于有预排序，此时数组接近有序
	int gap = n;//gap为间距，将整个数组分为几个段，并同时排序，以实现预排序效果
	while (gap > 1)
	{
		//经过大量验证gap/3时效率最高
		gap = gap / 3 + 1;//+1是为了确保最后一次是直接插入排序
		for (int i = 0; i < n - gap; i++)
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
			}
			a[end + gap] = temp;
		}
	}
}