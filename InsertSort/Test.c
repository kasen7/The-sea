#include"Sort.h"

void test1()
{
	int a[] = { 5,3,6,9,7,8,8,4,1,0 };
	//InsertSort(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	test1();
	return 0;
}