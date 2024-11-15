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
//������һ����
	//int end = 0;//endΪ���� ���е����һ���±�
	//int temp= a[end + 1];//tempʼ��Ϊ�������е�һ��


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

//����ֱ�Ӳ�������
	//���ؿ��ϴ���
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

	//������� _Ч������
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
//��������
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

//����ϣ������
	//ϣ�������������
	//1.Ԥ���򣺽������д��������Ų��С������ǰŲ��
	//2.ֱ�Ӳ�������������Ԥ���򣬴�ʱ����ӽ�����
	int gap = n;//gapΪ��࣬�����������Ϊ�����Σ���ͬʱ������ʵ��Ԥ����Ч��
	while (gap > 1)
	{
		//����������֤gap/3ʱЧ�����
		gap = gap / 3 + 1;//+1��Ϊ��ȷ�����һ����ֱ�Ӳ�������
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